/*=============================================================================
    Copyright (c) 2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef TRIVIALLY_COPYABLE_HPP
#define TRIVIALLY_COPYABLE_HPP

#include <boost/fusion/support/detail/is_trivially_copyable.hpp>

#include <boost/mpl/assert.hpp>
#include "../support/trivial.hpp"

using namespace boost::fusion;

#ifdef BOOST_FUSION_DETAIL_IS_TRIVIALLY_COPYABLE_CONFORMING
#   define BOOST_FUSION_ASSERT_TC BOOST_MPL_ASSERT
#else
#   define BOOST_FUSION_ASSERT_TC BOOST_MPL_ASSERT_NOT
#endif

BOOST_FUSION_ASSERT_TC((detail::is_trivially_copyable<FUSION_SEQUENCE<> >));
BOOST_FUSION_ASSERT_TC((detail::is_trivially_copyable<FUSION_SEQUENCE<int> >));
BOOST_FUSION_ASSERT_TC((detail::is_trivially_copyable<FUSION_SEQUENCE<int, int> >));
BOOST_FUSION_ASSERT_TC((detail::is_trivially_copyable<FUSION_SEQUENCE<int, int, int> >));
BOOST_MPL_ASSERT_NOT((detail::is_trivially_copyable<FUSION_SEQUENCE<int&> >));
BOOST_MPL_ASSERT_NOT((detail::is_trivially_copyable<FUSION_SEQUENCE<int, int&> >));
BOOST_MPL_ASSERT_NOT((detail::is_trivially_copyable<FUSION_SEQUENCE<int, int, int&> >));

BOOST_FUSION_ASSERT_TC((detail::is_trivially_copyable<FUSION_SEQUENCE<FUSION_SEQUENCE<> > >));
BOOST_FUSION_ASSERT_TC((detail::is_trivially_copyable<FUSION_SEQUENCE<FUSION_SEQUENCE<int> > >));
BOOST_FUSION_ASSERT_TC((detail::is_trivially_copyable<FUSION_SEQUENCE<FUSION_SEQUENCE<int>, FUSION_SEQUENCE<int, int> > >));
BOOST_FUSION_ASSERT_TC((detail::is_trivially_copyable<FUSION_SEQUENCE<FUSION_SEQUENCE<int>, FUSION_SEQUENCE<int, int>, FUSION_SEQUENCE<int, int, int> > >));

BOOST_FUSION_ASSERT_TC((detail::is_trivially_copyable<FUSION_SEQUENCE<int, trivial> >));
BOOST_MPL_ASSERT_NOT((detail::is_trivially_copyable<FUSION_SEQUENCE<int, user_provided_copy> >));
BOOST_MPL_ASSERT_NOT((detail::is_trivially_copyable<FUSION_SEQUENCE<int, user_provided_move> >));
BOOST_MPL_ASSERT_NOT((detail::is_trivially_copyable<FUSION_SEQUENCE<int, user_provided_dtor> >));

#ifdef BOOST_FUSION_DETAIL_IS_TRIVIALLY_COPYABLE_CONFORMING
#include <boost/core/lightweight_test.hpp>
#include <boost/core/addressof.hpp>
#include <boost/type_traits/aligned_storage.hpp>
#include <boost/type_traits/alignment_of.hpp>
#include <boost/fusion/sequence/intrinsic/at_c.hpp>
#include <boost/fusion/sequence/comparison/equal_to.hpp>
#include <cstring>

int main()
{
    typedef FUSION_SEQUENCE<char, double, const int*> seq_t;
    BOOST_MPL_ASSERT((detail::is_trivially_copyable<seq_t>));

    typedef boost::aligned_storage<sizeof(seq_t), boost::alignment_of<seq_t>::value>::type storage_t;

    storage_t* storage = new storage_t;

    int i = 42;

    const seq_t* src = new seq_t('\t', 3.14159265359, &i);
    std::memcpy(static_cast<void*>(storage), src, sizeof(seq_t));

    seq_t* dst = new seq_t;
    std::memcpy(dst, static_cast<void const*>(storage), sizeof(seq_t));

    BOOST_TEST((*src) == (*dst));
    BOOST_TEST(boost::fusion::at_c<0>(*src) == '\t');
    BOOST_TEST(boost::fusion::at_c<1>(*src) == 3.14159265359);
    BOOST_TEST(boost::fusion::at_c<2>(*src) == &i);
    BOOST_TEST(*boost::fusion::at_c<2>(*src) == 42);
    BOOST_TEST(boost::fusion::at_c<0>(*dst) == '\t');
    BOOST_TEST(boost::fusion::at_c<1>(*dst) == 3.14159265359);
    BOOST_TEST(boost::fusion::at_c<2>(*dst) == &i);
    BOOST_TEST(*boost::fusion::at_c<2>(*dst) == 42);

    delete dst;
    delete src;
    delete storage;

    return boost::report_errors();
}
#else
int main() { }
#endif
#endif

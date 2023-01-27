/*=============================================================================
    Copyright (c) 2010 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/detail/lightweight_test.hpp>

#include <boost/fusion/adapted/array.hpp>
#include <boost/fusion/sequence/intrinsic.hpp>
#include <boost/fusion/iterator.hpp>
#include <boost/fusion/support/is_sequence.hpp>
#include <boost/fusion/support/is_view.hpp>

#include <boost/mpl/assert.hpp>

#include "../with_or_without_fallback.hpp"

int main()
{
    using namespace boost::fusion;
    typedef int array_type[3];

    BOOST_MPL_ASSERT((traits::is_sequence<array_type>));
    BOOST_MPL_ASSERT_NOT((traits::is_view<array_type>));
    BOOST_STATIC_ASSERT(traits::is_sequence<array_type>::value);
    BOOST_STATIC_ASSERT(!traits::is_view<array_type>::value);

    array_type arr = {1,2,3};

    BOOST_TEST(*begin(arr) == 1);
    BOOST_TEST(*next(begin(arr)) == 2);
    BOOST_TEST(*advance_c<2>(begin(arr)) == 3);
    BOOST_TEST(prior(next(begin(arr))) == begin(arr));
    BOOST_TEST(*prior(end(arr)) == 3);
    BOOST_TEST(at_c<2>(arr) == 3);
    BOOST_TEST(size(arr) == 3);
    BOOST_TEST(distance(begin(arr), end(arr)) == 3);

    return boost::report_errors();
}


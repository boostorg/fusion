/*=============================================================================
    Copyright (c) 2021-2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include "boost_pfr.hpp"

#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/sequence/intrinsic/size.hpp>
#include <boost/fusion/sequence/intrinsic/empty.hpp>
#include <boost/fusion/sequence/intrinsic/begin.hpp>
#include <boost/fusion/sequence/intrinsic/end.hpp>
#include <boost/fusion/sequence/io/out.hpp>
#include <boost/fusion/iterator/equal_to.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/fusion/container/list/list.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>
#include <boost/fusion/sequence/comparison/equal_to.hpp>
#include <boost/fusion/sequence/comparison/not_equal_to.hpp>
#include <boost/fusion/sequence/comparison/less.hpp>
#include <boost/fusion/sequence/comparison/less_equal.hpp>
#include <boost/fusion/sequence/comparison/greater.hpp>
#include <boost/fusion/sequence/comparison/greater_equal.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <boost/fusion/mpl.hpp>
#include <boost/fusion/support/is_view.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/assert.hpp>
#include <iostream>

struct empty_struct {};

int
main()
{
    using boost::fusion::tuple_open;
    using boost::fusion::tuple_close;
    using boost::fusion::tuple_delimiter;
    using boost::fusion::make_vector;
    using boost::fusion::vector;
    using boost::fusion::list;
    namespace traits = boost::fusion::traits;
    namespace fusion = boost::fusion;

    // FIXME make this workable even with forced implicit reflection
    // std::cout << tuple_open('[');
    // std::cout << tuple_close(']');
    // std::cout << tuple_delimiter(", ");

    {
        BOOST_MPL_ASSERT_NOT((traits::is_view<empty_struct>));
        BOOST_STATIC_ASSERT(!traits::is_view<empty_struct>::value);
        empty_struct e;

        boost::fusion::out(std::cout, e) << std::endl;
        BOOST_TEST(e == make_vector());

        BOOST_STATIC_ASSERT(fusion::result_of::size<empty_struct>::value == 0);
        BOOST_MPL_ASSERT((fusion::result_of::empty<empty_struct>));

        BOOST_MPL_ASSERT((fusion::result_of::equal_to<
                          fusion::result_of::begin<empty_struct>::type,
                fusion::result_of::end<empty_struct>::type>));
    }

    {
        int counter = 0;
        empty_struct empty;
        boost::fusion::for_each(empty, [&](){counter+=1;});
        BOOST_TEST(counter == 0);
    }

    {
        fusion::vector<> v;
        empty_struct e;
        BOOST_TEST(v == e);
        BOOST_TEST_NOT(e != v);
        BOOST_TEST_NOT(v < e);
        BOOST_TEST(v <= e);
        BOOST_TEST_NOT(e > v);
        BOOST_TEST(e >= v);
    }

    {
        empty_struct e;

        // conversion from empty_struct to vector
        fusion::vector<> v(e);
        v = e;

        // FIXME
        // conversion from empty_struct to list
        //fusion::list<> l(e);
        //l = e;
    }

    // FIXME
    // mpl binding, it's possible after resolving https://github.com/boostorg/mpl/issues/71
    // BOOST_MPL_ASSERT((mpl::is_sequence<empty_struct>));

    return boost::report_errors();
}


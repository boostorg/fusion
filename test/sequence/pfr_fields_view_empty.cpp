/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/view/pfr_fields_view.hpp>
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
    using namespace boost::fusion;
    using namespace boost;

    std::cout << tuple_open('[');
    std::cout << tuple_close(']');
    std::cout << tuple_delimiter(", ");

    {
        using view_t = pfr_fields_view<empty_struct>;
        static_assert(traits::is_view<view_t>::value, "");
        empty_struct e;
        pfr_fields_view<empty_struct> view(e);

        std::cout << view << std::endl;
        BOOST_TEST(view == make_vector());

        static_assert(fusion::result_of::size<view_t>::value == 0, "");
        static_assert(fusion::result_of::empty<view_t>::value, "");

        static_assert(fusion::result_of::equal_to<
                          fusion::result_of::begin<view_t>::type,
                fusion::result_of::end<view_t>::type>::value, "");
    }

    {
        int counter = 0;
        empty_struct empty;
        pfr_fields_view<empty_struct> view(empty);
        boost::fusion::for_each(view, [&](){counter+=1;});
        BOOST_TEST(counter == 0);
    }

    {
        fusion::vector<> v;
        empty_struct e;
        pfr_fields_view<empty_struct> view(e);
        BOOST_TEST(    v    == view);
        BOOST_TEST_NOT(view != v);
        BOOST_TEST_NOT(v    <  view);
        BOOST_TEST(    v    <= view);
        BOOST_TEST_NOT(view >  v);
        BOOST_TEST(    view >= v);
    }

    {
        empty_struct e;
        pfr_fields_view<empty_struct> view(e);

        // conversion from empty_struct to vector
        fusion::vector<> v(view);
        v = view;

        // FIXME
        // conversion from empty_struct to list
        //fusion::list<> l(view);
        //l = view;
    }

    static_assert(mpl::is_sequence< pfr_fields_view<empty_struct> >::value, "");

    return boost::report_errors();
}

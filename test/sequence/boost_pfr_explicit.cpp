/*=============================================================================
    Copyright (c) 2021-2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/adapted/boost_pfr_explicit.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/sequence/intrinsic/size.hpp>
#include <boost/fusion/sequence/intrinsic/empty.hpp>
#include <boost/fusion/sequence/intrinsic/front.hpp>
#include <boost/fusion/sequence/intrinsic/back.hpp>
#include <boost/fusion/support/is_view.hpp>
#include <boost/fusion/sequence/io/out.hpp>
#include <boost/fusion/sequence/comparison/equal_to.hpp>
#include <boost/fusion/sequence/comparison/not_equal_to.hpp>
#include <boost/fusion/sequence/comparison/less.hpp>
#include <boost/fusion/sequence/comparison/less_equal.hpp>
#include <boost/fusion/sequence/comparison/greater.hpp>
#include <boost/fusion/sequence/comparison/greater_equal.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/fusion/container/list/list.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>
#include <boost/fusion/mpl.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/assert.hpp>
#include <iostream>
#include <string>

struct just_point {
    int x;
    int y;
    int z;
};

struct point_declared_as_reflectable {
    int x;
    int y;
    int z;
};
BOOST_FUSION_FORCE_PFR_REFLECTABLE(point_declared_as_reflectable)

// Make sure tag_of can be used with an incomplete type, and explicit adapter for Boost PFR won't broke this
struct incomplete;
typedef boost::fusion::traits::tag_of<incomplete>::type Tag;
BOOST_STATIC_ASSERT((boost::is_same<Tag, boost::fusion::non_fusion_tag>::value));

int
main()
{
    using namespace boost::fusion;
    using namespace boost;

    std::cout << tuple_open('[');
    std::cout << tuple_close(']');
    std::cout << tuple_delimiter(", ");

    {
        static_assert(std::is_same<
            boost::fusion::traits::tag_of<just_point>::type
          , boost::fusion::non_fusion_tag>::value, "");
    }

    {
        using point = point_declared_as_reflectable;
        static_assert(!traits::is_view< point >::value, "");
        point p = {123, 456, 789};

        std::cout << at_c<0>(p) << std::endl;
        std::cout << at_c<1>(p) << std::endl;
        std::cout << at_c<2>(p) << std::endl;
        std::cout << p << std::endl;
        BOOST_TEST(p == make_vector(123, 456, 789));

        at_c<0>(p) = 6;
        at_c<1>(p) = 9;
        at_c<2>(p) = 12;

        BOOST_TEST(p == make_vector(6, 9, 12));

        static_assert(boost::fusion::result_of::size<point>::value == 3, "");
        static_assert(!boost::fusion::result_of::empty<point>::value, "");
        static_assert(std::is_same<
            boost::fusion::traits::tag_of<point>::type
          , boost::fusion::boost_pfr_tag>::value, "");
        static_assert(!boost::fusion::result_of::equal_to<boost::fusion::result_of::begin<point>::type,
                                                          boost::fusion::result_of::end<point>::type>::value, "");

        BOOST_TEST(front(p) == 6);
        BOOST_TEST(back(p) == 12);
    }

    return boost::report_errors();
} 



/*=============================================================================
    Copyright (c) 2021-2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/adapted/boost_pfr.hpp>
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

namespace namespaced_type {
    using integer = int;
}

namespace ns {
    struct point {
        int x;
        int y;
        namespaced_type::integer z;
    };

    struct guaranteed_nonconstexpr_string {
        std::string value;
        explicit guaranteed_nonconstexpr_string(std::string value) : value(std::move(value)) {
            std::cout << "mark to ensure nonconstexpr" << std::endl;
        }
    };

    inline bool operator== (const guaranteed_nonconstexpr_string& rhs, const guaranteed_nonconstexpr_string& lhs) {
        return (rhs.value == lhs.value);
    }

    // Testing non-constexpr compatible types
    struct employee {
        guaranteed_nonconstexpr_string name;
        guaranteed_nonconstexpr_string nickname;
    };
}

struct s { int m; };

int
main()
{
    using namespace boost::fusion;
    using namespace boost;
    using ns::point;

    std::cout << tuple_open('[');
    std::cout << tuple_close(']');
    std::cout << tuple_delimiter(", ");

    {
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
                                                          boost::fusion::result_of::end<point>::type>::value);

        BOOST_TEST(front(p) == 6);
        BOOST_TEST(back(p) == 12);
    }

    {
        vector<int, float, int> v1(4, 2.f, 2);
        point v2 = {5, 3, 3};
        vector<long, double, int> v3(5, 4., 4);
        BOOST_TEST(v1 < v2);
        BOOST_TEST(v1 <= v2);
        BOOST_TEST(v2 > v1);
        BOOST_TEST(v2 >= v1);
        BOOST_TEST(v2 < v3);
        BOOST_TEST(v2 <= v3);
        BOOST_TEST(v3 > v2);
        BOOST_TEST(v3 >= v2);
    }

    {
        // conversion from point to vector
        point p = {5, 3, 3};
        vector<int, long, int> v(p);
        v = p;
    }

    {
        // conversion from point to list
        point p = {5, 3, 3};
        list<int, long, int> l(p);
        l = p;
    }

    { // begin/end
        using namespace boost::fusion;
        using boost::is_same;

        using b = boost::fusion::result_of::begin<s>::type;
        using e = boost::fusion::result_of::end<s>::type;
        // this fails
        static_assert(is_same<boost::fusion::result_of::next<b>::type, e>::value);
    }

    {
        // FIXME
        // mpl binding, it's possible after resolving https://github.com/boostorg/mpl/issues/71
        //static_assert(boost::mpl::is_sequence<ns::point>::value);
        //static_assert(boost::is_same<
        //                  boost::fusion::result_of::value_at_c<ns::point,0>::type
        //        , boost::mpl::front<ns::point>::type>::value);
    }

    {
        ns::employee emp{ns::guaranteed_nonconstexpr_string("John Doe"),
		                 ns::guaranteed_nonconstexpr_string("jdoe")};
        std::cout << at_c<0>(emp).value << std::endl;
        std::cout << at_c<1>(emp).value << std::endl;

        fusion::vector<ns::guaranteed_nonconstexpr_string, ns::guaranteed_nonconstexpr_string> v1(
            ns::guaranteed_nonconstexpr_string("John Doe"), ns::guaranteed_nonconstexpr_string("jdoe"));
        BOOST_TEST(emp == v1);
    }

    {
        int a[3] = {100, 200, 300};
        static_assert(std::is_same<
            boost::fusion::traits::tag_of<decltype(a)>::type
          , boost::fusion::non_fusion_tag>::value, "");
    }

    {
        using seq = ns::point;
        using c_vec = const ns::point;
        using first = boost::fusion::result_of::begin<seq>::type;
        using c_first = boost::fusion::result_of::begin<c_vec>::type;

        static_assert(boost::is_same<boost::fusion::result_of::value_of<first>::type, int>::value);
        static_assert(boost::is_same<boost::fusion::result_of::value_of<c_first>::type, int>::value);
    }

    {
        using seq = ns::point;
        using c_vec = const ns::point;

        BOOST_MPL_ASSERT((boost::is_same<boost::fusion::result_of::value_at<seq, boost::mpl::int_<0> >::type, int>));
        BOOST_MPL_ASSERT((boost::is_same<boost::fusion::result_of::value_at<c_vec, boost::mpl::int_<0> >::type, int>));
    }

    return boost::report_errors();
} 



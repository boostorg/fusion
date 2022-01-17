/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/view/pfr_fields_view.hpp>
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
    typedef int integer;
}

namespace ns {
    struct point {
        int x;
        int y;
        namespaced_type::integer z;
    };

    // Testing non-constexpr compatible types
#if BOOST_PFR_USE_CPP17 != 0
    struct employee {
        std::string name;
        std::string nickname;
    };
#endif // BOOST_PFR_USE_CPP17
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
        using view_t = pfr_fields_view<point>;
        static_assert(traits::is_view<view_t>::value, "");
        point p = {123, 456, 789};
        pfr_fields_view<point> view(p);

        std::cout << at_c<0>(view) << std::endl;
        std::cout << at_c<1>(view) << std::endl;
        std::cout << at_c<2>(view) << std::endl;
        std::cout << view << std::endl;
        BOOST_TEST(view == make_vector(123, 456, 789));

        at_c<0>(view) = 6;
        at_c<1>(view) = 9;
        at_c<2>(view) = 12;
        BOOST_TEST(view == make_vector(6, 9, 12));

        static_assert(boost::fusion::result_of::size<view_t>::value == 3, "");
        static_assert(!boost::fusion::result_of::empty<view_t>::value, "");

        BOOST_TEST(front(view) == 6);
        BOOST_TEST( back(view) == 12);
    }

    {
        vector<int, float, int> v1(4, 2.f, 2);
        point v2 = {5, 3, 3};
        vector<long, double, int> v3(5, 4., 4);
        pfr_fields_view<point> view(v2);
        BOOST_TEST(v1   <  view);
        BOOST_TEST(v1   <= view);
        BOOST_TEST(view >  v1);
        BOOST_TEST(view >= v1);
        BOOST_TEST(view <  v3);
        BOOST_TEST(view <= v3);
        BOOST_TEST(v3   >  view);
        BOOST_TEST(v3   >= view);
    }

    {
        // conversion from point to vector
        point p = {5, 3, 3};
        pfr_fields_view<point> view(p);
        vector<int, long, int> v(view);
        v = view;
    }

    {
        // conversion from point to list
        point p = {5, 3, 3};
        pfr_fields_view<point> view(p);
        list<int, long, int> l(view);
        l = view;
    }

    { // begin/end
        using namespace boost::fusion;
        using boost::is_same;
        using view_t = pfr_fields_view<s>;

        typedef boost::fusion::result_of::begin<view_t>::type b;
        typedef boost::fusion::result_of::end<view_t>::type e;
        // this fails
        static_assert(is_same<boost::fusion::result_of::next<b>::type, e>::value, "");
    }

    {
        using view_t = pfr_fields_view<ns::point>;
        static_assert(mpl::is_sequence<view_t>::value, "");
        static_assert(boost::is_same<
                          boost::fusion::result_of::value_at_c<view_t,0>::type
                , mpl::front<view_t>::type>::value, "");
    }

#if BOOST_PFR_USE_CPP17 != 0
    {
        ns::employee emp{"John Doe", "jdoe"};
        pfr_fields_view<ns::employee> view(emp);
        std::cout << at_c<0>(view) << std::endl;
        std::cout << at_c<1>(view) << std::endl;

        fusion::vector<std::string, std::string> v1("John Doe", "jdoe");
        BOOST_TEST(view == v1);
    }
#endif // BOOST_PFR_USE_CPP17

    return boost::report_errors();
}
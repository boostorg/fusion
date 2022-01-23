/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/view/pfr_view.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/sequence/intrinsic/size.hpp>
#include <boost/fusion/sequence/intrinsic/empty.hpp>
#include <boost/fusion/sequence/intrinsic/front.hpp>
#include <boost/fusion/sequence/intrinsic/back.hpp>
#include <boost/fusion/sequence/io/out.hpp>
#include <boost/fusion/support/is_view.hpp>
#include <boost/fusion/sequence/comparison/equal_to.hpp>
#include <boost/fusion/sequence/comparison/not_equal_to.hpp>
#include <boost/fusion/sequence/comparison/less.hpp>
#include <boost/fusion/sequence/comparison/less_equal.hpp>
#include <boost/fusion/sequence/comparison/greater.hpp>
#include <boost/fusion/sequence/comparison/greater_equal.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>
#include <iostream>

namespace namespaced_type {
    typedef int integer;
}

namespace ns {
    struct point {
        int x;
        int y;
        namespaced_type::integer z;
    };
}

template<typename T>
void generic_test(T& t) {
    using namespace boost::fusion;
    using namespace boost;

    using view_t = pfr_view<T>;
    static_assert(traits::is_view<view_t>::value, "");

    pfr_view<T> view(t);
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
    BOOST_TEST(back(view) == 12);
}


int main()
{
    using namespace boost::fusion;
    using namespace boost;
    using ns::point;

    std::cout << tuple_open('[');
    std::cout << tuple_close(']');
    std::cout << tuple_delimiter(", ");

    {
        point p = {123, 456, 789};
        generic_test(p);
    }

    {
        vector<int, int, int> seq (123, 456, 789);
        generic_test(seq);
    }

    return boost::report_errors();
}

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

struct A
{
    int first;
    int second;
    int third;
};
BOOST_FUSION_FORCE_PFR_REFLECTABLE(A)

template<typename T1, typename T2, typename T3>
struct is_same_thernary 
    : std::integral_constant<bool, (std::is_same<T1, T2>::value && std::is_same<T2, T3>::value)>
{
};

int
main()
{
    {
        A a{100, 200, 300};

        using namespace boost::fusion;

        static_assert(is_same_thernary<
            boost::fusion::result_of::prior< boost::fusion::result_of::end<decltype(a)>::type >::type
            , std::remove_const_t<decltype(prior(end(a)))>
            , boost_pfr_iterator<A, 2>
            >::value, "");

        BOOST_TEST(*prior(end(a)) == 300);
        BOOST_TEST(*next(begin(a)) == 200);
        BOOST_TEST(distance(begin(a), end(a)) == 3);
        BOOST_TEST(advance< boost::mpl::int_<3> >(begin(a)) == end(a));
    }

    {
        A a;  // it must be instead of std::declval
        const A ca{800, 600, 500};

        using namespace boost::fusion;

        static_assert(is_same_thernary<
            boost::fusion::result_of::deref<decltype(begin(a))>::type
            , decltype(deref(begin(a)))
            , int&
        >::value, "");
        static_assert(is_same_thernary<
            boost::fusion::result_of::deref<decltype(begin(ca))>::type
            , decltype(deref(begin(ca)))
            , const int&
        >::value, "");

        static_assert(is_same_thernary<
            boost::fusion::result_of::deref<decltype( advance<boost::mpl::int_<-1>>(end(a)) )>::type
            , decltype(deref(advance<boost::mpl::int_<-1>>(end(a))))
            , int&
        >::value, "");
        static_assert(is_same_thernary<
            boost::fusion::result_of::deref<decltype( advance<boost::mpl::int_<-1>>(end(ca)) )>::type
            , decltype(deref(advance<boost::mpl::int_<-1>>(end(ca))))
            , const int&
        >::value, "");
    }

    {
        A a;  // it must be instead of std::declval
        const A ca{800, 600, 500};

        using namespace boost::fusion;

        static_assert(is_same_thernary<
            boost::fusion::result_of::at_c<decltype(a), 0>::type
            , decltype(at_c<0>(a))
            , int&
        >::value, "");
        static_assert(is_same_thernary<
            boost::fusion::result_of::at_c<decltype(ca), 0>::type
            , decltype(at_c<0>(ca))
            , const int&
        >::value, "");
    }

    {
        A a{100, 200, 300};
        const A ca{800, 600, 500};

        using namespace boost::fusion;

        static_assert(is_same_thernary<
            boost::fusion::result_of::value_of< boost::fusion::result_of::begin<decltype(a)>::type >::type
            , boost::fusion::result_of::value_at< decltype(a), boost::mpl::int_<0> >::type
            , int
        >::value, "");

        static_assert(is_same_thernary<
            boost::fusion::result_of::value_of< boost::fusion::result_of::begin<decltype(ca)>::type >::type
            , boost::fusion::result_of::value_at< decltype(ca), boost::mpl::int_<0> >::type
            , int
        >::value, "");
    }

    return boost::report_errors();
} 



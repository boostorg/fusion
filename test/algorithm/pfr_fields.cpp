/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/algorithm/auxiliary/pfr_fields.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/sequence/intrinsic/at_c.hpp>
#include <boost/fusion/sequence/intrinsic/size.hpp>
#include <boost/fusion/sequence/intrinsic/empty.hpp>
#include <boost/fusion/sequence/intrinsic/front.hpp>
#include <boost/fusion/sequence/intrinsic/back.hpp>
#include <boost/fusion/sequence/intrinsic/end.hpp>
#include <boost/fusion/sequence/intrinsic/value_at.hpp>
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
#include <boost/fusion/iterator.hpp>
#include <boost/fusion/mpl.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/assert.hpp>
#include <iostream>
#include <string>
#include <type_traits>

template<typename T1, typename T2, typename T3>
struct is_same_thernary 
    : std::integral_constant<bool, (std::is_same<T1, T2>::value && std::is_same<T2, T3>::value)>
{
};



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

struct A
{
    int first;
    int second;
    int third;
};

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
        using pfr_t = boost::fusion::result_of::pfr_fields<point>::type;
        static_assert(traits::is_view< pfr_t >::value, "");
        point p = {123, 456, 789};

        std::cout << at_c<0>(pfr_fields(p)) << std::endl;
        std::cout << at_c<1>(pfr_fields(p)) << std::endl;
        std::cout << at_c<2>(pfr_fields(p)) << std::endl;
        std::cout << pfr_fields(p) << std::endl;
        BOOST_TEST(pfr_fields(p) == make_vector(123, 456, 789));

        at_c<0>(pfr_fields(p)) = 6;
        at_c<1>(pfr_fields(p)) = 9;
        at_c<2>(pfr_fields(p)) = 12;
        BOOST_TEST(pfr_fields(p) == make_vector(6, 9, 12));

        BOOST_STATIC_ASSERT(boost::fusion::result_of::size<pfr_t>::value == 3);
        BOOST_STATIC_ASSERT(!boost::fusion::result_of::empty<pfr_t>::value);

        BOOST_TEST(front(pfr_fields(p)) == 6);
        BOOST_TEST(back(pfr_fields(p)) == 12);
    }

    {
        A a{100, 200, 300};
        auto view = boost::fusion::pfr_fields(a);

        using namespace boost::fusion;

        BOOST_MPL_ASSERT((is_same_thernary<
            boost::fusion::result_of::pfr_fields<A>::type
            , decltype(pfr_fields(a))
            , pfr_fields_view<A> 
        >));
        BOOST_MPL_ASSERT((is_same_thernary<
            boost::fusion::result_of::prior< boost::fusion::result_of::end<decltype(view)>::type >::type
            , std::remove_const_t<decltype(prior(end(view)))>
            , pfr_fields_view_iterator<A, boost::mpl::int_<2> >
            >));

        BOOST_TEST(*prior(end(view)) == 300);
        BOOST_TEST(*next(begin(view)) == 200);
        BOOST_TEST(distance(begin(view), end(view)) == 3);
        BOOST_TEST(advance< boost::mpl::int_<3> >(begin(view)) == end(view));
    }

    {
        A a;  // it must be instead of std::declval
        const A ca{800, 600, 500};

        using namespace boost::fusion;

        BOOST_MPL_ASSERT((is_same_thernary<
            boost::fusion::result_of::deref<decltype(begin(pfr_fields(a)))>::type
            , decltype(deref(begin(pfr_fields(a))))
            , int&
        >));
        BOOST_MPL_ASSERT((is_same_thernary<
            boost::fusion::result_of::deref<decltype(begin(pfr_fields(ca)))>::type
            , decltype(deref(begin(pfr_fields(ca))))
            , const int&
        >));

        BOOST_MPL_ASSERT((is_same_thernary<
            boost::fusion::result_of::deref<decltype( advance<boost::mpl::int_<-1>>(end(pfr_fields(a))) )>::type
            , decltype(deref(advance<boost::mpl::int_<-1>>(end(pfr_fields(a)))))
            , int&
        >));
        BOOST_MPL_ASSERT((is_same_thernary<
            boost::fusion::result_of::deref<decltype( advance<boost::mpl::int_<-1>>(end(pfr_fields(ca))) )>::type
            , decltype(deref(advance<boost::mpl::int_<-1>>(end(pfr_fields(ca)))))
            , const int&
        >));
    }

    {
        A a;  // it must be instead of std::declval
        const A ca{800, 600, 500};

        using namespace boost::fusion;

        BOOST_MPL_ASSERT((is_same_thernary<
            boost::fusion::result_of::at_c<decltype(pfr_fields(a)), 0>::type
            , decltype(at_c<0>(pfr_fields(a)))
            , int&
        >));
        BOOST_MPL_ASSERT((is_same_thernary<
            boost::fusion::result_of::at_c<decltype(pfr_fields(ca)), 0>::type
            , decltype(at_c<0>(pfr_fields(ca)))
            , const int&
        >));
    }

    {
        A a{100, 200, 300};
        const A ca{800, 600, 500};

        using namespace boost::fusion;

        BOOST_MPL_ASSERT((is_same_thernary<
            boost::fusion::result_of::value_of< boost::fusion::result_of::begin<decltype(pfr_fields(a))>::type >::type
            , boost::fusion::result_of::value_at< decltype(pfr_fields(a)), boost::mpl::int_<0> >::type
            , int
        >));

        BOOST_MPL_ASSERT((is_same_thernary<
            boost::fusion::result_of::value_of< boost::fusion::result_of::begin<decltype(pfr_fields(ca))>::type >::type
            , boost::fusion::result_of::value_at< decltype(pfr_fields(ca)), boost::mpl::int_<0> >::type
            , int
        >));
    }

    return boost::report_errors();
}
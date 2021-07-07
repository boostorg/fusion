/*============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/
#include <boost/fusion/sequence/comparison/less.hpp>
#include <boost/fusion/sequence/comparison/less_equal.hpp>
#include <boost/fusion/sequence/comparison/greater.hpp>
#include <boost/fusion/sequence/comparison/greater_equal.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/core/lightweight_test.hpp>

namespace test
{
    template <typename PairType>
    void pair_compare(PairType& p)
    {
        boost::fusion::vector<int, float> v1(4, 3.3f);
        boost::fusion::vector<long, double> v2(5, 4.4);
        BOOST_TEST(v1 < p);
        BOOST_TEST(v1 <= p);
        BOOST_TEST(p > v1);
        BOOST_TEST(p >= v1);
        BOOST_TEST(p < v2);
        BOOST_TEST(p <= v2);
        BOOST_TEST(v2 > p);
        BOOST_TEST(v2 >= p);
    }
}

#include <boost/fusion/sequence/comparison/equal_to.hpp>
#include <boost/fusion/sequence/comparison/not_equal_to.hpp>
#include <boost/fusion/sequence/intrinsic/empty.hpp>
#include <boost/fusion/sequence/intrinsic/size.hpp>
#include <boost/fusion/sequence/intrinsic/front.hpp>
#include <boost/fusion/sequence/intrinsic/back.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/container/list/list.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>
#include <boost/fusion/mpl.hpp>
#include <boost/fusion/support/is_view.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/type_traits/is_same.hpp>

namespace test
{
    template <typename PairType>
    void pair_access_and_modify(PairType& p)
    {
        BOOST_MPL_ASSERT((boost::mpl::is_sequence<PairType>));
        BOOST_MPL_ASSERT((
            boost::is_same<int, typename boost::mpl::front<PairType>::type>
        ));
        BOOST_MPL_ASSERT((
            boost::is_same<
                std::string
              , typename boost::mpl::back<PairType>::type
            >
        ));
        BOOST_MPL_ASSERT((
            boost::is_same<int, typename boost::mpl::at_c<PairType,0>::type>
        ));
        BOOST_MPL_ASSERT((
            boost::is_same<
                std::string
              , typename boost::mpl::at_c<PairType,1>::type
            >
        ));
        BOOST_MPL_ASSERT((
            boost::mpl::equal_to<
                boost::fusion::result_of::size<PairType>
              , boost::mpl::int_<2>
            >
        ));
        BOOST_MPL_ASSERT_NOT((boost::fusion::traits::is_view<PairType>));
        BOOST_MPL_ASSERT_NOT((boost::fusion::result_of::empty<PairType>));

        BOOST_TEST(p == boost::fusion::make_vector(123, "Hola!!!"));

        boost::fusion::vector<int, std::string> v(p);
        BOOST_TEST(v == p);
        v = p;
        BOOST_TEST(v == p);

        boost::fusion::list<int, std::string> l(p);
        BOOST_TEST(l == p);
        l = p;
        BOOST_TEST(l == p);

        boost::fusion::at_c<0>(p) = 6;
        boost::fusion::at_c<1>(p) = "mama mia";
        BOOST_TEST(p == boost::fusion::make_vector(6, "mama mia"));
        BOOST_TEST(boost::fusion::front(p) == 6);
#if 0
        BOOST_TEST(boost::fusion::back(p) == "mama mia");
#endif
    }
}


/*=============================================================================
    Copyright (c) 2016 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/config.hpp>
#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/list.hpp>
#include <boost/fusion/include/deque.hpp>

#include <boost/tuple/tuple.hpp>
#include <boost/fusion/include/boost_tuple.hpp>

#ifndef BOOST_NO_CXX11_HDR_TUPLE
#include <tuple>
#include <boost/fusion/include/std_tuple.hpp>
#endif

#include <boost/fusion/include/mpl.hpp>
#include <boost/mpl/transform.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/assert.hpp>

struct left
{
    template <typename L, typename> struct apply { typedef L type; };
};

template <typename Seq> struct test
{
    typedef typename boost::mpl::transform<Seq, Seq, left>::type type;
};

using namespace boost::fusion;
BOOST_MPL_ASSERT((boost::is_same<test<boost::fusion::vector<> >::type, boost::fusion::vector<> >));
BOOST_MPL_ASSERT((boost::is_same<test<boost::fusion::list<> >::type, boost::fusion::list<> >));
BOOST_MPL_ASSERT((boost::is_same<test<boost::fusion::deque<> >::type, boost::fusion::deque<> >));

BOOST_MPL_ASSERT((boost::is_same<test<boost::tuples::tuple<> >::type, boost::tuples::tuple<> >));

#ifndef BOOST_NO_CXX11_HDR_TUPLE
BOOST_MPL_ASSERT((boost::is_same<test<std::tuple<> >::type, std::tuple<> >));
#endif

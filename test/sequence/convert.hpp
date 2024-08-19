/*=============================================================================
    Copyright (c) 2015 Kohei Takahashi

    Use modification and distribution are subject to the Boost Software
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
==============================================================================*/

#include <string>
#include <boost/config.hpp>
#include <boost/core/lightweight_test.hpp>

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/include/convert.hpp>
#include <boost/fusion/include/at.hpp>

#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/deque.hpp>
#include <boost/fusion/include/list.hpp>
#include <boost/fusion/include/boost_tuple.hpp>
#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
#include <boost/fusion/include/std_tuple.hpp>
#endif

#if BOOST_FUSION_PFR_ENABLED
#if BOOST_FUSION_PFR_ENABLE_IMPLICIT_REFLECTION
#include <boost/fusion/adapted/boost_pfr.hpp>
#endif
#include <boost/fusion/adapted/boost_pfr_explicit.hpp>
#endif

template <typename Tag>
void test(FUSION_SEQUENCE<int, std::string> const& seq)
{
    typedef typename
        boost::fusion::result_of::convert<
            Tag
          , FUSION_SEQUENCE<int, std::string>
        >::type
    type;

    type v = boost::fusion::convert<Tag>(seq);
    BOOST_TEST((boost::fusion::at_c<0>(v) == 123));
    BOOST_TEST((boost::fusion::at_c<1>(v) == "Hola!!!"));
}

int main()
{
    FUSION_SEQUENCE<int, std::string> seq(123, "Hola!!!");
    test<boost::fusion::vector_tag>(seq);
    test<boost::fusion::deque_tag>(seq);
    test<boost::fusion::cons_tag>(seq);
    test<boost::fusion::boost_tuple_tag>(seq);
#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    test<boost::fusion::std_tuple_tag>(seq);
#endif
#if BOOST_FUSION_PFR_ENABLED
    // There is no 'convert' for Boost PFR, and it's impossible to implement
    //test<boost::fusion::boost_pfr_tag>(seq);
#endif
    return boost::report_errors();
}


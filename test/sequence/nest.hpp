/*=============================================================================
    Copyright (C) 2015 Kohei Takahshi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <utility>
#include <boost/config.hpp>
#include <boost/fusion/include/as_deque.hpp>
#include <boost/fusion/include/as_list.hpp>
#include <boost/fusion/include/as_vector.hpp>

template<typename C, template<typename> class As>
void test_from_sequence_rvalue()
{
    typename As<C>::type dst((C()));
    (void)dst;
}

template<typename C, template<typename> class As>
void test_from_sequence_const_lvalue()
{
    C src;
    typename As<C>::type dst(src);
    (void)dst;
}

template<typename C, template<typename> class As>
void test_from_sequence_lvalue()
{
    const C src;
    typename As<C>::type dst(src);
    (void)dst;
}

template<typename C, template<typename> class As>
void test_from_sequence()
{
// the following tests do not work in all cases for C++03
#if defined(BOOST_FUSION_HAS_VARIADIC_VECTOR)
    test_from_sequence_rvalue<C, As>();
    test_from_sequence_const_lvalue<C, As>();
    test_from_sequence_lvalue<C, As>();
#endif
}

template <typename C>
void test_copy()
{
    C src;
    C dst = src;
    (void)dst;
}

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
template <typename C>
void test_move()
{
    C src;
    C dst = std::move(src);
    (void)dst;
}
#endif

template <typename C>
void test_all()
{
// as_deque and as_list do not work in C++03 or C++11 mode
//    test_from_sequence<C, boost::fusion::result_of::as_deque>();
//    test_from_sequence<C, boost::fusion::result_of::as_list>();
    test_from_sequence<C, boost::fusion::result_of::as_vector>();
    test_copy<C>();
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    test_move<C>();
#endif
}

void
test()
{
    using namespace boost::fusion;

    test_all<FUSION_SEQUENCE<FUSION_SEQUENCE<> > >();
    test_all<FUSION_SEQUENCE<FUSION_SEQUENCE<>, int> >();
    test_all<FUSION_SEQUENCE<int, FUSION_SEQUENCE<> > >();
    test_all<FUSION_SEQUENCE<int, FUSION_SEQUENCE<>, float> >();

    test_all<FUSION_SEQUENCE<FUSION_SEQUENCE<int> > >();
    test_all<FUSION_SEQUENCE<FUSION_SEQUENCE<int>, int> >();
    test_all<FUSION_SEQUENCE<int, FUSION_SEQUENCE<int> > >();
    test_all<FUSION_SEQUENCE<int, FUSION_SEQUENCE<int>, float> >();

    test_all<FUSION_SEQUENCE<FUSION_SEQUENCE<int, float> > >();
    test_all<FUSION_SEQUENCE<FUSION_SEQUENCE<int, float>, int> >();
    test_all<FUSION_SEQUENCE<int, FUSION_SEQUENCE<int, float> > >();
    test_all<FUSION_SEQUENCE<int, FUSION_SEQUENCE<int, float>, float> >();

    test_all<FUSION_SEQUENCE<FUSION_SEQUENCE<>, FUSION_SEQUENCE<> > >();
    test_all<FUSION_SEQUENCE<FUSION_SEQUENCE<int>, FUSION_SEQUENCE<> > >();
    test_all<FUSION_SEQUENCE<FUSION_SEQUENCE<>, FUSION_SEQUENCE<int> > >();
    test_all<
        FUSION_SEQUENCE<FUSION_SEQUENCE<int>, FUSION_SEQUENCE<float> >
    >();
    test_all<
        FUSION_SEQUENCE<FUSION_SEQUENCE<int, float>, FUSION_SEQUENCE<float> >
    >();
    test_all<
        FUSION_SEQUENCE<FUSION_SEQUENCE<int>, FUSION_SEQUENCE<float, int> >
    >();
    test_all<
        FUSION_SEQUENCE<
            FUSION_SEQUENCE<int, float>, FUSION_SEQUENCE<float, int>
        >
    >();
}


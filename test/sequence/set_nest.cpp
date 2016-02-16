/*=============================================================================
    Copyright (C) 2016 Kohei Takahshi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <utility>
#include <boost/config.hpp>
#include <boost/fusion/container/set/set.hpp>
#include <boost/core/lightweight_test.hpp>

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
    test_copy<C>();
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    test_move<C>();
#endif
}

void
test()
{
    using namespace boost::fusion;

    test_all<set<set<> > >();
    test_all<set<set<>, int> >();
    test_all<set<int, set<> > >();
    test_all<set<int, set<>, float> >();

    test_all<set<set<int> > >();
    test_all<set<set<int>, int> >();
    test_all<set<int, set<int> > >();
    test_all<set<int, set<int>, float> >();

    test_all<set<set<int>, float> >();
    test_all<set<set<int>, float, int> >();
}

int
main()
{
    test();
    return boost::report_errors();
}


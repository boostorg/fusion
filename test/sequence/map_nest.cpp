/*=============================================================================
    Copyright (C) 2016 Kohei Takahshi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <utility>
#include <boost/config.hpp>
#include <boost/fusion/container/map/map.hpp>
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

struct k1;
struct k2;
struct k3;
struct k4;

void
test()
{
    using namespace boost::fusion;

    test_all<map<pair<k1, map<> > > >();
    test_all<map<pair<k1, map<> >, pair<k2, int> > >();
    test_all<map<pair<k1, int>, pair<k2, map<> > > >();
    test_all<map<pair<k1, int>, pair<k2, map<> >, pair<k3, float> > >();

    test_all<map<pair<k1, map<pair<k2, int> > > > >();
    test_all<map<pair<k1, map<pair<k2, int> > >, pair<k3, int> > >();
    test_all<map<pair<k1, int>, pair<k2, map<pair<k3, int> > > > >();
    test_all<map<pair<k1, int>, pair<k2, map<pair<k3, int> > >, pair<k4, float> > >();

    test_all<map<pair<k1, map<pair<k2, int>, pair<k3, float> > > > >();
    test_all<map<pair<k1, map<pair<k2, int>, pair<k3, float> > >, pair<k4, int> > >();
    test_all<map<pair<k1, int>, map<pair<k2, int>, pair<k3, float> > > >();
    test_all<map<pair<k1, int>, map<pair<k2, int>, pair<k3, float> >, pair<k4, float> > >();
}

int
main()
{
    test();
    return boost::report_errors();
}


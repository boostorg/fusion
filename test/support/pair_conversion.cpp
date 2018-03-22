/*=============================================================================
    Copyright (c) 2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <utility>
#include <boost/config.hpp>
#include <boost/fusion/support/pair.hpp>

using namespace boost::fusion;

struct eat_int
{
    eat_int(int);
};

struct eat_pair
{
    template <typename K, typename V>
    eat_pair(pair<K, V>);
};

int main()
{
    pair<void, int> p;

    pair<void, eat_int> ci(p);

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
    pair<void, eat_int> mi(std::move(p));
#endif

    // eat_pair can't be converted from int, but can be pair.
    // So pair(eat_pair) should be called rather than pair(pair<void, eat_pair>).
    pair<void, eat_pair> cp(p);

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
    pair<void, eat_pair> mp(std::move(p));
#endif
}

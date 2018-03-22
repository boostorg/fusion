/*=============================================================================
    Copyright (c) 2015,2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/core/ignore_unused.hpp>
#include <boost/fusion/support/pair.hpp>

using namespace boost::fusion;

template <typename C>
void copy(C value)
{
    pair<int, C> src(value);
    pair<int, C> dest = src;
    boost::ignore_unused(dest);
}

int main()
{
    copy<pair<void, float> >(42.195f);
    copy<pair<int, float> >(42.195f);

    float f;
    pair<void, float&> r(f);
    copy<pair<void, float&> >(r);
}


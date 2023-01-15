/*=============================================================================
    Copyright (c) 2021-2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#define BOOST_FUSION_PFR_ENABLED                       0
#define BOOST_FUSION_PFR_ENABLE_IMPLICIT_REFLECTION    1
#define BOOST_PFR_ENABLED                              1
#define BOOST_PFR_ENABLE_IMPLICIT_REFLECTION           0

#include <boost/fusion/support/config.hpp>
#include <boost/static_assert.hpp>

BOOST_STATIC_ASSERT(BOOST_FUSION_PFR_ENABLED != BOOST_PFR_ENABLED);
BOOST_STATIC_ASSERT(BOOST_FUSION_PFR_ENABLE_IMPLICIT_REFLECTION != BOOST_PFR_ENABLE_IMPLICIT_REFLECTION);

int main() { }


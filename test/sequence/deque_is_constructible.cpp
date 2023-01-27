/*=============================================================================
    Copyright (c) 2015 Louis Dionne

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/config.hpp>

#ifndef BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <type_traits>
#include <boost/fusion/include/deque.hpp>
#include <boost/fusion/adapted/boost_pfr/force.hpp>

#include "../with_or_without_fallback.hpp"

struct Dummy { };
BOOST_FUSION_FORCE_PFR_NONREFLECTABLE(Dummy)

// Make sure deque's constructor is SFINAE-friendly.
static_assert(!std::is_constructible<boost::fusion::deque<int>, Dummy const&>::value, "");

#endif


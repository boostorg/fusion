/*=============================================================================
    Copyright (c) 2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

// This header provides ability for testing Boost PFR integration(both implicit and explicit) in different ways to include it.

#if BOOST_FUSION_USE_PFR_EXPLICIT_0
#include <boost/fusion/adapted/boost_pfr_explicit.hpp>
#elif BOOST_FUSION_USE_PFR_EXPLICIT_1
#include <boost/fusion/include/boost_pfr_explicit.hpp>
#elif BOOST_FUSION_USE_PFR_EXPLICIT_2
#define BOOST_FUSION_PFR_ENABLE_IMPLICIT_REFLECTION 0
#include <boost/fusion/adapted.hpp>

#elif BOOST_FUSION_USE_PFR_IMPLICIT_0
#include <boost/fusion/adapted/boost_pfr.hpp>
#elif BOOST_FUSION_USE_PFR_IMPLICIT_1
#include <boost/fusion/include/boost_pfr.hpp>
#elif BOOST_FUSION_USE_PFR_IMPLICIT_2
#include <boost/fusion/adapted.hpp>

#else
#error You have to specify the way you need to include Boost PFR integration.
#endif


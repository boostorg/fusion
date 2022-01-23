/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_ALGORITHM_AUXILIARY_02192011_0907)
#define FUSION_ALGORITHM_AUXILIARY_02192011_0907

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/algorithm/auxiliary/copy.hpp>
#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
#include <boost/fusion/algorithm/auxiliary/move.hpp>
#endif

// Unfortunately, there is no way to determine the compatibility of the pfr library with the current compiler.
// The "boost/fusion/algorithm/auxiliary/pfr.hpp" include has been commented out to ensure backward compatibility
// Please include it manually in your project

// #if !defined(BOOST_FUSION_NO_PFR)
// #include <boost/fusion/algorithm/auxiliary/pfr.hpp>
// #endif

#endif

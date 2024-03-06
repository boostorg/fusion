/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_FUSION_ADAPTED_30122005_1420
#define BOOST_FUSION_ADAPTED_30122005_1420

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/adapted/adt.hpp>
#include <boost/fusion/adapted/array.hpp>
#include <boost/fusion/adapted/boost_array.hpp>
#include <boost/fusion/adapted/boost_tuple.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/adapted/std_pair.hpp>
#include <boost/fusion/adapted/struct.hpp>

// The std_tuple_iterator adaptor only supports implementations
// using variadic templates
#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
#include <boost/fusion/adapted/std_tuple.hpp>
#endif

// The Boost PFR Library is a C++14 library, but this library also
// may be not supported in some C++14 compilers.
// Even if the library is supported in user's environment, that
// still doesn't mean the environment supports implicit reflection
// and that also doesn't mean the user wants implicit reflection.
#if BOOST_FUSION_PFR_ENABLED
#if BOOST_FUSION_PFR_ENABLE_IMPLICIT_REFLECTION
#include <boost/fusion/adapted/boost_pfr.hpp>
#endif
#include <boost/fusion/adapted/boost_pfr_explicit.hpp>
#endif

#endif


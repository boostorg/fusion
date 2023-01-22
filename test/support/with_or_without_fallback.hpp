/*=============================================================================
    Copyright (c) 2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

// This header provides ability for regression test of Boost PFR adapter.

#if BOOST_FUSION_USE_TAG_OF_FALLBACK
// this branch may be without fallback in old compilers
#include <boost/fusion/adapted.hpp>
#elif BOOST_FUSION_DO_NOT_USE_TAG_OF_FALLBACK
// just nothing
#else
#error Do you need to use tag_of fallback or you do not?
#endif


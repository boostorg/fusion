/*=============================================================================
    Copyright (c) 2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/fusion/container/vector/detail/config.hpp>

#ifndef BOOST_FUSION_HAS_VARIADIC_VECTOR
int main() { }
#else

#include <boost/fusion/container/vector/vector.hpp>
#define FUSION_SEQUENCE boost::fusion::vector
#include "trivially_copyable.hpp"
#endif


/*=============================================================================
    Copyright (c) 2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/fusion/tuple/tuple_fwd.hpp>

#ifndef BOOST_FUSION_HAS_VARIADIC_TUPLE
int main() { }
#else

#include <boost/fusion/tuple/tuple.hpp>
#define FUSION_SEQUENCE boost::fusion::tuple
#include "trivially_copyable.hpp"
#endif


/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2009-2011 Christopher Schmidt
    Copyright (c) 2013-2014 Damien Buhl

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_STRUCT_AUTO_ADAPT_STRUCT_HPP
#define BOOST_FUSION_ADAPTED_STRUCT_AUTO_ADAPT_STRUCT_HPP

#include <boost/preprocessor/seq/for_each.hpp> 

#include <boost/typeof/typeof.hpp> 

#include <boost/fusion/include/adapt_struct.hpp>

#define BOOST_FUSION_AUTO_ADAPT_STRUCT_FILLER(r, data, elem)                    \
    (BOOST_TYPEOF(data::elem), elem)                                            \

#define BOOST_FUSION_AUTO_ADAPT_STRUCT(NAME, ATTRIBUTES)                        \
    BOOST_FUSION_ADAPT_STRUCT(NAME,                                             \
        BOOST_PP_SEQ_FOR_EACH(                                                  \
          BOOST_FUSION_AUTO_ADAPT_STRUCT_FILLER, NAME, ATTRIBUTES)              \
        )

#endif

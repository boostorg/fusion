/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2009-2010 Hartmut Kaiser
    Copyright (c) 2010-2011 Christopher Schmidt
    Copyright (c) 2013-2014 Damien Buhl


    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_STRUCT_AUTO_ADAPT_STRUCT_NAMED_HPP
#define BOOST_FUSION_ADAPTED_STRUCT_AUTO_ADAPT_STRUCT_NAMED_HPP

#include <boost/fusion/adapted/struct/adapt_struct_named.hpp>
#include <boost/fusion/adapted/struct/auto_adapt_struct.hpp>

#define BOOST_FUSION_AUTO_ADAPT_STRUCT_NAMED_NS(                                \
    WRAPPED_TYPE, NAMESPACE_SEQ, NAME, ATTRIBUTES)                              \
                                                                                \
    BOOST_FUSION_ADAPT_STRUCT_NAMED_NS(                                         \
        WRAPPED_TYPE, NAMESPACE_SEQ, NAME,                                      \
        BOOST_PP_SEQ_FOR_EACH(                                                  \
            BOOST_FUSION_AUTO_ADAPT_STRUCT_FILLER, WRAPPED_TYPE, ATTRIBUTES))   \

#define BOOST_FUSION_AUTO_ADAPT_STRUCT_NAMED(WRAPPED_TYPE, NAME, ATTRIBUTES)    \
    BOOST_FUSION_AUTO_ADAPT_STRUCT_NAMED_NS(                                    \
        WRAPPED_TYPE,(boost)(fusion)(adapted),NAME,ATTRIBUTES)

#endif

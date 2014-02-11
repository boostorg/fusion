/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2007 Dan Marsden
    Copyright (c) 2009-2011 Christopher Schmidt
    Copyright (c) 2013-2014 Damien Buhl

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_STRUCT_AUTO_ADAPT_ASSOC_STRUCT_HPP
#define BOOST_FUSION_ADAPTED_STRUCT_AUTO_ADAPT_ASSOC_STRUCT_HPP

#include <boost/preprocessor/seq/for_each.hpp> 
#include <boost/preprocessor/tuple/elem.hpp>

#include <boost/typeof/typeof.hpp> 

#include <boost/fusion/adapted/struct/adapt_assoc_struct.hpp>
#include <boost/preprocessor/cat.hpp>

#define BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_FILLER_0(A, B)                     \
    ((A, B)) BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_FILLER_1 
#define BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_FILLER_1(A, B)                     \
    ((A, B)) BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_FILLER_0 
#define BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_FILLER_0_END 
#define BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_FILLER_1_END 

#define BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_TYPE_DEDUCER(r, NAME, ATTRIBUTE)   \
     (BOOST_TYPEOF(NAME::BOOST_PP_TUPLE_ELEM(2, 0, ATTRIBUTE)),                 \
      BOOST_PP_TUPLE_ELEM(2, 0, ATTRIBUTE),                                     \
      BOOST_PP_TUPLE_ELEM(2, 1, ATTRIBUTE))

#define BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT(NAME, ATTRIBUTES)                  \
    BOOST_FUSION_ADAPT_ASSOC_STRUCT(NAME,                                       \
        BOOST_PP_SEQ_FOR_EACH(                                                  \
            BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_TYPE_DEDUCER,                  \
            NAME,                                                               \
            BOOST_PP_CAT(                                                       \
                BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_FILLER_0 ATTRIBUTES,_END)  \
            )                                                                   \
        ) 

#endif

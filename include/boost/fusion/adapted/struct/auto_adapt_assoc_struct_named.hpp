/*=============================================================================
    Copyright (c) 2010-2011 Christopher Schmidt
    Copyright (c) 2013-2014 Damien Buhl

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_STRUCT_AUTO_ADAPT_ASSOC_STRUCT_NAMED_HPP
#define BOOST_FUSION_ADAPTED_STRUCT_AUTO_ADAPT_ASSOC_STRUCT_NAMED_HPP

#include <boost/preprocessor/seq/for_each.hpp> 
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/cat.hpp>

#include <boost/typeof/typeof.hpp> 

#include <boost/fusion/adapted/struct/adapt_assoc_struct_named.hpp>

#define BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_NAMED_FILLER_0(A, B)               \
    ((A, B)) BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_NAMED_FILLER_1 
#define BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_NAMED_FILLER_1(A, B)               \
    ((A, B)) BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_NAMED_FILLER_0 
#define BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_NAMED_FILLER_0_END 
#define BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_NAMED_FILLER_1_END 

#define BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_NAMED_TYPE_DEDUCER(                \
    r, NAME, ATTRIBUTE)                                                         \
     (BOOST_TYPEOF(                                                             \
            BOOST_PP_TUPLE_ELEM(                                                \
                2,                                                              \
                0,                                                              \
                NAME)                                                           \
            ::BOOST_PP_TUPLE_ELEM(                                              \
                2,                                                              \
                0,                                                              \
                ATTRIBUTE)),                                                    \
      BOOST_PP_TUPLE_ELEM(2, 0, ATTRIBUTE),                                     \
      BOOST_PP_TUPLE_ELEM(2, 1, ATTRIBUTE))

#define BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_NAMED(                             \
    WRAPPED_TYPE, NAME, ATTRIBUTES)                                             \
                                                                                \
    BOOST_FUSION_ADAPT_ASSOC_STRUCT_NAMED(WRAPPED_TYPE,                         \
        NAME,                                                                   \
        BOOST_PP_SEQ_FOR_EACH(                                                  \
            BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_NAMED_TYPE_DEDUCER,            \
            (WRAPPED_TYPE, NAME),                                               \
            BOOST_PP_CAT(                                                       \
                BOOST_FUSION_AUTO_ADAPT_ASSOC_STRUCT_NAMED_FILLER_0 ATTRIBUTES, \
                _END)                                                           \
            )                                                                   \
        ) 


#endif

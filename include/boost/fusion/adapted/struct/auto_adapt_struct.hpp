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
#include <boost/preprocessor/seq/pop_front.hpp>
#include <boost/preprocessor/variadic/elem.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>

#include <boost/typeof/typeof.hpp> 

#include <boost/fusion/adapted/struct/adapt_struct.hpp>

#define BOOST_FUSION_AUTO_ADAPT_STRUCT_TYPE_DEDUCER(r, NAME, ATTRIBUTE)         \
     (BOOST_TYPEOF(NAME::ATTRIBUTE), ATTRIBUTE)

#define BOOST_FUSION_AUTO_ADAPT_STRUCT(...)                                     \
    BOOST_FUSION_AUTO_ADAPT_STRUCT_BASE(                                        \
        BOOST_PP_VARIADIC_ELEM(0, __VA_ARGS__),                                 \
        BOOST_PP_SEQ_POP_FRONT(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)))

#define BOOST_FUSION_AUTO_ADAPT_STRUCT_BASE(NAME, ATTRIBUTES)                   \
    BOOST_FUSION_ADAPT_STRUCT(NAME,                                             \
        BOOST_PP_SEQ_FOR_EACH(                                                  \
            BOOST_FUSION_AUTO_ADAPT_STRUCT_TYPE_DEDUCER, NAME, ATTRIBUTES)      \
        )



#define BOOST_FUSION_ADAPT_STRUCT_FILLER_0(X, Y)                                \
    ((X, Y)) BOOST_FUSION_ADAPT_STRUCT_FILLER_1
#define BOOST_FUSION_ADAPT_STRUCT_FILLER_1(X, Y)                                \
    ((X, Y)) BOOST_FUSION_ADAPT_STRUCT_FILLER_0
#define BOOST_FUSION_ADAPT_STRUCT_FILLER_0_END
#define BOOST_FUSION_ADAPT_STRUCT_FILLER_1_END

#define BOOST_FUSION_ADAPT_STRUCT(NAME, ATTRIBUTES)                             \
    BOOST_FUSION_ADAPT_STRUCT_BASE(                                             \
        (0),                                                                    \
        (0)(NAME),                                                              \
        struct_tag,                                                             \
        0,                                                                      \
        BOOST_PP_CAT(BOOST_FUSION_ADAPT_STRUCT_FILLER_0(0,0)ATTRIBUTES,_END),   \
        BOOST_FUSION_ADAPT_STRUCT_C)



#endif

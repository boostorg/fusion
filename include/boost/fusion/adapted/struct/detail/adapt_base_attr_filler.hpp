/*=============================================================================
    Copyright (c) 2013-2014 Damien Buhl

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_STRUCT_DETAIL_ADAPT_BASE_ATTR_FILLER_HPP
#define BOOST_FUSION_ADAPTED_STRUCT_DETAIL_ADAPT_BASE_ATTR_FILLER_HPP

#include <boost/config.hpp>
#include <boost/fusion/adapted/struct/detail/preprocessor/is_seq.hpp>

#include <boost/preprocessor/empty.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/facilities/is_empty.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/push_front.hpp>

#define BOOST_FUSION_ADAPT_STRUCT_FILLER_0(X, Y)                                \
    BOOST_FUSION_ADAPT_STRUCT_ATTRIBUTE_FILLER(X,Y)                             \
    BOOST_FUSION_ADAPT_STRUCT_FILLER_1

#define BOOST_FUSION_ADAPT_STRUCT_FILLER_1(X, Y)                                \
    BOOST_FUSION_ADAPT_STRUCT_ATTRIBUTE_FILLER(X,Y)                             \
    BOOST_FUSION_ADAPT_STRUCT_FILLER_0

#define BOOST_FUSION_ADAPT_STRUCT_FILLER_0_END
#define BOOST_FUSION_ADAPT_STRUCT_FILLER_1_END

#define BOOST_FUSION_ADAPT_STRUCT_ATTRIBUTE_FILLER(X, Y)                        \
    BOOST_PP_IF(BOOST_PP_IS_EMPTY(X),                                           \
      ((1, (Y))),                                                               \
      ((2, (X,Y)))                                                              \
    )

#define BOOST_FUSION_ADAPT_STRUCT_WRAPPEDATTR_SIZE(ATTRIBUTE)                   \
  BOOST_PP_TUPLE_ELEM(2, 0, ATTRIBUTE)

#define BOOST_FUSION_ADAPT_STRUCT_WRAPPEDATTR(ATTRIBUTE)                        \
  BOOST_PP_TUPLE_ELEM(2, 1, ATTRIBUTE)

#define BOOST_FUSION_ADAPT_ASSOC_STRUCT_FILLER_0(X, Y, Z)                       \
    BOOST_FUSION_ADAPT_ASSOC_STRUCT_ATTRIBUTE_FILLER(X, Y, Z)                   \
    BOOST_FUSION_ADAPT_ASSOC_STRUCT_FILLER_1

#define BOOST_FUSION_ADAPT_ASSOC_STRUCT_FILLER_1(X, Y, Z)                       \
    BOOST_FUSION_ADAPT_ASSOC_STRUCT_ATTRIBUTE_FILLER(X, Y, Z)                   \
    BOOST_FUSION_ADAPT_ASSOC_STRUCT_FILLER_0

#define BOOST_FUSION_ADAPT_ASSOC_STRUCT_FILLER_0_END
#define BOOST_FUSION_ADAPT_ASSOC_STRUCT_FILLER_1_END

#define BOOST_FUSION_ADAPT_ASSOC_STRUCT_ATTRIBUTE_FILLER(X, Y, Z)               \
    BOOST_PP_IF(BOOST_PP_IS_EMPTY(X),                                           \
      ((2, (Y,Z))),                                                             \
      ((3, (X,Y,Z)))                                                            \
    )

#define BOOST_FUSION_ADAPT_ASSOC_STRUCT_WRAPPEDATTR_GET_KEY(ATTRIBUTE)          \
    BOOST_PP_TUPLE_ELEM(                                                        \
        BOOST_FUSION_ADAPT_STRUCT_WRAPPEDATTR_SIZE(ATTRIBUTE),                  \
        BOOST_PP_SUB(BOOST_FUSION_ADAPT_STRUCT_WRAPPEDATTR_SIZE(ATTRIBUTE), 1), \
        BOOST_FUSION_ADAPT_STRUCT_WRAPPEDATTR(ATTRIBUTE))


#if BOOST_PP_VARIADICS

#   define BOOST_FUSION_ADAPT_STRUCT_ATTRIBUTES_FILLER_OP(r, data, elem)        \
        BOOST_PP_IF(BOOST_FUSION_PP_IS_SEQ(elem),                               \
            BOOST_PP_CAT( BOOST_FUSION_ADAPT_STRUCT_FILLER_0 elem ,_END),       \
            BOOST_FUSION_ADAPT_STRUCT_ATTRIBUTE_FILLER(BOOST_FUSION_ADAPT_AUTO, \
                elem)                                                           \
        )

#   define BOOST_FUSION_ADAPT_STRUCT_ATTRIBUTES_FILLER(...)                     \
        BOOST_PP_SEQ_PUSH_FRONT(                                                \
            BOOST_PP_SEQ_FOR_EACH(                                              \
                BOOST_FUSION_ADAPT_STRUCT_ATTRIBUTES_FILLER_OP,                 \
                unused, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)),                 \
                (0,0)                                                           \
        )

#endif // BOOST_PP_VARIADICS

#endif

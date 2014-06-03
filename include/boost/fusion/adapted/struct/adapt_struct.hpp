/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2009-2011 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_STRUCT_ADAPT_STRUCT_HPP
#define BOOST_FUSION_ADAPTED_STRUCT_ADAPT_STRUCT_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/preprocessor/config/config.hpp>
#include <boost/preprocessor/variadic.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/push_front.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/empty.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/facilities/is_empty.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/remove_const.hpp>

#include <boost/fusion/adapted/struct/detail/extension.hpp>
#include <boost/fusion/adapted/struct/detail/adapt_base.hpp>
#include <boost/fusion/adapted/struct/detail/at_impl.hpp>
#include <boost/fusion/adapted/struct/detail/is_view_impl.hpp>
#include <boost/fusion/adapted/struct/detail/is_sequence_impl.hpp>
#include <boost/fusion/adapted/struct/detail/value_at_impl.hpp>
#include <boost/fusion/adapted/struct/detail/category_of_impl.hpp>
#include <boost/fusion/adapted/struct/detail/size_impl.hpp>
#include <boost/fusion/adapted/struct/detail/begin_impl.hpp>
#include <boost/fusion/adapted/struct/detail/end_impl.hpp>
#include <boost/fusion/adapted/struct/detail/value_of_impl.hpp>
#include <boost/fusion/adapted/struct/detail/deref_impl.hpp>
#include <boost/fusion/adapted/struct/detail/preprocessor/is_seq.hpp>

#if BOOST_PP_VARIADICS

#define BOOST_FUSION_ADAPT_STRUCT_CREATE_MEMBER_TUPLE(...)                      \
    BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 2),         \
        BOOST_PP_IF(BOOST_PP_IS_EMPTY(BOOST_PP_VARIADIC_ELEM(0, __VA_ARGS__)),  \
          ((1, (BOOST_PP_VARIADIC_ELEM(1, __VA_ARGS__)) )),                     \
          ((2, BOOST_PP_VARIADIC_TO_TUPLE(__VA_ARGS__)))                        \
        ),                                                                      \
        ((1, (BOOST_PP_VARIADIC_ELEM(0, __VA_ARGS__)) ))                        \
    )

#define BOOST_FUSION_ADAPT_STRUCT_FILLER_0(...)                                 \
    BOOST_FUSION_ADAPT_STRUCT_CREATE_MEMBER_TUPLE(__VA_ARGS__)                  \
    BOOST_FUSION_ADAPT_STRUCT_FILLER_1
#define BOOST_FUSION_ADAPT_STRUCT_FILLER_1(...)                                 \
    BOOST_FUSION_ADAPT_STRUCT_CREATE_MEMBER_TUPLE(__VA_ARGS__)                  \
    BOOST_FUSION_ADAPT_STRUCT_FILLER_0

#define BOOST_FUSION_ADAPT_STRUCT_FILLER_0_END
#define BOOST_FUSION_ADAPT_STRUCT_FILLER_1_END

#else // BOOST_PP_VARIADICS

#define BOOST_FUSION_ADAPT_STRUCT_CREATE_MEMBER_TUPLE(X, Y)                     \
    BOOST_PP_IF(BOOST_PP_IS_EMPTY(X),                                           \
      ((1, (Y))),                                                               \
      ((2, (X,Y)))                                                              \
    )

#define BOOST_FUSION_ADAPT_STRUCT_FILLER_0(X, Y)                                \
    BOOST_FUSION_ADAPT_STRUCT_CREATE_MEMBER_TUPLE(X,Y)                          \
    BOOST_FUSION_ADAPT_STRUCT_FILLER_1

#define BOOST_FUSION_ADAPT_STRUCT_FILLER_1(X, Y)                                \
    BOOST_FUSION_ADAPT_STRUCT_CREATE_MEMBER_TUPLE(X,Y)                          \
    BOOST_FUSION_ADAPT_STRUCT_FILLER_0

#define BOOST_FUSION_ADAPT_STRUCT_FILLER_0_END
#define BOOST_FUSION_ADAPT_STRUCT_FILLER_1_END

#endif // BOOST_PP_VARIADICS

#define BOOST_FUSION_ADAPT_AUTO BOOST_PP_EMPTY()

#define BOOST_FUSION_ADAPT_STRUCT_C(TEMPLATE_PARAMS_SEQ, NAME_SEQ, I, ATTRIBUTE)\
    BOOST_FUSION_ADAPT_STRUCT_C_BASE(                                           \
        TEMPLATE_PARAMS_SEQ,                                                    \
        NAME_SEQ,                                                               \
        I,                                                                      \
        BOOST_PP_EMPTY,                                                         \
        BOOST_PP_TUPLE_ELEM(2, 1, ATTRIBUTE),                                   \
        BOOST_PP_TUPLE_ELEM(2, 0, ATTRIBUTE))

#define BOOST_FUSION_ADAPT_TPL_STRUCT(TEMPLATE_PARAMS_SEQ,NAME_SEQ, ATTRIBUTES) \
    BOOST_FUSION_ADAPT_STRUCT_BASE(                                             \
        (1)TEMPLATE_PARAMS_SEQ,                                                 \
        (1)NAME_SEQ,                                                            \
        struct_tag,                                                             \
        0,                                                                      \
        ((0,0)) BOOST_PP_CAT(                                                   \
            BOOST_FUSION_ADAPT_STRUCT_FILLER_0 ATTRIBUTES,_END),                \
        BOOST_FUSION_ADAPT_STRUCT_C)


#if BOOST_PP_VARIADICS

#define BOOST_FUSION_ADAPT_STRUCT_PROCESS_PARAM(r, data, elem)                  \
    BOOST_PP_IF(BOOST_FUSION_PP_IS_SEQ(elem),                                   \
      BOOST_PP_CAT( BOOST_FUSION_ADAPT_STRUCT_FILLER_0 elem ,_END),             \
      BOOST_FUSION_ADAPT_STRUCT_CREATE_MEMBER_TUPLE(elem)                       \
   )

#define BOOST_FUSION_ADAPT_STRUCT_CREATE_MEMBER_TUPLE_FROM_VARIADICS(...)       \
    BOOST_PP_SEQ_PUSH_FRONT(  \
    BOOST_PP_SEQ_FOR_EACH(BOOST_FUSION_ADAPT_STRUCT_PROCESS_PARAM, unused, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)), (0,0))

#define BOOST_FUSION_ADAPT_STRUCT(NAME, ...)                                    \
    BOOST_FUSION_ADAPT_STRUCT_BASE(                                             \
        (0),                                                                    \
        (0)(NAME),                                                              \
        struct_tag,                                                             \
        0,                                                                      \
        BOOST_FUSION_ADAPT_STRUCT_CREATE_MEMBER_TUPLE_FROM_VARIADICS(__VA_ARGS__), \
        BOOST_FUSION_ADAPT_STRUCT_C)
        
#else // BOOST_PP_VARIADICS

#define BOOST_FUSION_ADAPT_STRUCT(NAME, ATTRIBUTES)                             \
    BOOST_FUSION_ADAPT_STRUCT_BASE(                                             \
        (0),                                                                    \
        (0)(NAME),                                                              \
        struct_tag,                                                             \
        0,                                                                      \
        BOOST_PP_CAT( BOOST_FUSION_ADAPT_STRUCT_FILLER_0(0,0)ATTRIBUTES,_END),  \
        BOOST_FUSION_ADAPT_STRUCT_C)

#endif // BOOST_PP_VARIADICS

#define BOOST_FUSION_ADAPT_STRUCT_AS_VIEW(NAME, ATTRIBUTES)                     \
    BOOST_FUSION_ADAPT_STRUCT_BASE(                                             \
        (0),                                                                    \
        (0)(NAME),                                                              \
        struct_tag,                                                             \
        1,                                                                      \
        BOOST_PP_CAT(BOOST_FUSION_ADAPT_STRUCT_FILLER_0(0,0)ATTRIBUTES,_END),   \
        BOOST_FUSION_ADAPT_STRUCT_C)

#endif

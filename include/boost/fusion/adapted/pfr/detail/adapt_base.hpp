/*=============================================================================
    Copyright (c) 2021 Denis Mikhailov

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_PFR_DETAIL_ADAPT_BASE_HPP
#define BOOST_FUSION_ADAPTED_PFR_DETAIL_ADAPT_BASE_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/config.hpp>
#include <boost/fusion/support/tag_of_fwd.hpp>

#include <boost/preprocessor/empty.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/seq.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/comparison/less.hpp>
#include <boost/preprocessor/logical/not.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/tag.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_reference.hpp>

#include <boost/typeof/typeof.hpp>

#define BOOST_FUSION_ADAPT_PFR_UNPACK_NAME_TEMPLATE_PARAMS(SEQ)                 \
    BOOST_PP_SEQ_HEAD(SEQ)<BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_TAIL(SEQ))>           \
    BOOST_PP_EMPTY()

#define BOOST_FUSION_ADAPT_PFR_UNPACK_NAME(SEQ)                                 \
    BOOST_PP_IF(                                                                \
        BOOST_PP_SEQ_HEAD(SEQ),                                                 \
        BOOST_FUSION_ADAPT_PFR_UNPACK_NAME_TEMPLATE_PARAMS,                     \
        BOOST_PP_SEQ_HEAD)(BOOST_PP_SEQ_TAIL(SEQ))

#define BOOST_FUSION_ADAPT_PFR_UNPACK_TEMPLATE_PARAMS_IMPL_C(R, _, ELEM)        \
    (typename ELEM)
#define BOOST_FUSION_ADAPT_PFR_UNPACK_TEMPLATE_PARAMS_IMPL(SEQ)                 \
    BOOST_PP_SEQ_ENUM(                                                          \
        BOOST_PP_SEQ_FOR_EACH(                                                  \
            BOOST_FUSION_ADAPT_PFR_UNPACK_TEMPLATE_PARAMS_IMPL_C,               \
            _,                                                                  \
            BOOST_PP_SEQ_TAIL(SEQ)))
#define BOOST_FUSION_ADAPT_PFR_UNPACK_TEMPLATE_PARAMS(SEQ)                      \
    BOOST_PP_IF(                                                                \
        BOOST_PP_SEQ_HEAD(SEQ),                                                 \
        BOOST_FUSION_ADAPT_PFR_UNPACK_TEMPLATE_PARAMS_IMPL,                     \
        BOOST_PP_TUPLE_EAT(1))(SEQ)

#ifdef BOOST_NO_PARTIAL_SPECIALIZATION_IMPLICIT_DEFAULT_ARGS
#   define BOOST_FUSION_ADAPT_PFR_TAG_OF_SPECIALIZATION(                        \
        MODIFIER, TEMPLATE_PARAMS_SEQ, NAME_SEQ, TAG)                           \
                                                                                \
    template<                                                                   \
        BOOST_FUSION_ADAPT_PFR_UNPACK_TEMPLATE_PARAMS(TEMPLATE_PARAMS_SEQ)      \
    >                                                                           \
    struct tag_of<                                                              \
        BOOST_FUSION_ADAPT_PFR_UNPACK_NAME(NAME_SEQ) MODIFIER                   \
      , void                                                                    \
    >                                                                           \
    {                                                                           \
        typedef TAG type;                                                       \
    };
#else
#   define BOOST_FUSION_ADAPT_PFR_TAG_OF_SPECIALIZATION(                        \
        MODIFIER, TEMPLATE_PARAMS_SEQ, NAME_SEQ, TAG)                           \
                                                                                \
    template<                                                                   \
        BOOST_FUSION_ADAPT_PFR_UNPACK_TEMPLATE_PARAMS(TEMPLATE_PARAMS_SEQ)      \
    >                                                                           \
    struct tag_of<BOOST_FUSION_ADAPT_PFR_UNPACK_NAME(NAME_SEQ) MODIFIER>        \
    {                                                                           \
        typedef TAG type;                                                       \
    };
#endif

#define BOOST_FUSION_ADAPT_PFR_BASE(                                            \
    TEMPLATE_PARAMS_SEQ,                                                        \
    NAME_SEQ,                                                                   \
    TAG)                                                                        \
                                                                                \
namespace boost                                                                 \
{                                                                               \
    namespace fusion                                                            \
    {                                                                           \
        namespace traits                                                        \
        {                                                                       \
            BOOST_FUSION_ADAPT_PFR_TAG_OF_SPECIALIZATION(                       \
                BOOST_PP_EMPTY(), TEMPLATE_PARAMS_SEQ, NAME_SEQ, TAG)           \
            BOOST_FUSION_ADAPT_PFR_TAG_OF_SPECIALIZATION(                       \
                const, TEMPLATE_PARAMS_SEQ, NAME_SEQ, TAG)                      \
        }                                                                       \
    }                                                                           \
                                                                                \
    namespace mpl                                                               \
    {                                                                           \
        template<typename>                                                      \
        struct sequence_tag;                                                    \
                                                                                \
        template<                                                               \
            BOOST_FUSION_ADAPT_PFR_UNPACK_TEMPLATE_PARAMS(                      \
                TEMPLATE_PARAMS_SEQ)                                            \
        >                                                                       \
        struct sequence_tag<BOOST_FUSION_ADAPT_PFR_UNPACK_NAME(NAME_SEQ)>       \
        {                                                                       \
            typedef fusion::fusion_sequence_tag type;                           \
        };                                                                      \
                                                                                \
        template<                                                               \
            BOOST_FUSION_ADAPT_PFR_UNPACK_TEMPLATE_PARAMS(                      \
                TEMPLATE_PARAMS_SEQ)                                            \
        >                                                                       \
        struct sequence_tag<                                                    \
            BOOST_FUSION_ADAPT_PFR_UNPACK_NAME(NAME_SEQ) const                  \
        >                                                                       \
        {                                                                       \
            typedef fusion::fusion_sequence_tag type;                           \
        };                                                                      \
    }                                                                           \
}

#endif //BOOST_FUSION_ADAPTED_PFR_DETAIL_ADAPT_BASE_HPP

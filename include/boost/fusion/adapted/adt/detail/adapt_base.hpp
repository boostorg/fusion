/*=============================================================================
    Copyright (c) 2001-2009 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden
    Copyright (c) 2010 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_ADT_DETAIL_ADAPT_BASE_HPP
#define BOOST_FUSION_ADAPTED_ADT_DETAIL_ADAPT_BASE_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/adapted/struct/detail/adapt_auto.hpp>

#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/seq/seq.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/remove_const.hpp>

#include <boost/typeof/typeof.hpp>

#define BOOST_FUSION_ADAPT_ADT_GET_IDENTITY_TEMPLATE_IMPL(TEMPLATE_PARAMS_SEQ)  \
    typename detail::get_identity<                                              \
        lvalue                                                                  \
      , BOOST_PP_SEQ_ELEM(1,TEMPLATE_PARAMS_SEQ)                                \
    >::type

#define BOOST_FUSION_ADAPT_ADT_GET_IDENTITY_NON_TEMPLATE_IMPL(                  \
    TEMPLATE_PARAMS_SEQ)                                                        \
                                                                                \
    boost::remove_const<boost::remove_reference<lvalue>::type>::type

#define BOOST_FUSION_ADAPT_ADT_ATTRIBUTE_GETEXPR(ATTRIBUTE,                     \
    ATTRIBUTE_TUPEL_SIZE, DEDUCE_TYPE)                                          \
    BOOST_PP_TUPLE_ELEM(ATTRIBUTE_TUPEL_SIZE,                                   \
        BOOST_PP_IF(DEDUCE_TYPE, 0, 2), ATTRIBUTE)

#define BOOST_FUSION_ADAPT_ADT_ATTRIBUTE_SETEXPR(ATTRIBUTE,                     \
    ATTRIBUTE_TUPEL_SIZE, DEDUCE_TYPE)                                          \
    BOOST_PP_TUPLE_ELEM(ATTRIBUTE_TUPEL_SIZE,                                   \
        BOOST_PP_IF(DEDUCE_TYPE, 1, 3), ATTRIBUTE)

#define BOOST_FUSION_ADT_ATTRIBUTE_TYPEOF(                                      \
    NAME_SEQ, ATTRIBUTE, ATTRIBUTE_TUPEL_SIZE, PREFIX)                          \
                                                                                \
    struct deduced_attr_type {                                                  \
      static const BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)& obj;        \
      typedef BOOST_TYPEOF(                                                     \
                  PREFIX() BOOST_FUSION_ADAPT_ADT_ATTRIBUTE_GETEXPR(            \
                      ATTRIBUTE, ATTRIBUTE_TUPEL_SIZE, 1)) type;                \
    };                                                                          \
                                                                                \
    typedef boost::remove_const<                                                \
        deduced_attr_type::type                                                 \
    >::type type;                                                               \
                                                                                \
    typedef boost::add_const<                                                   \
        deduced_attr_type::type                                                 \
    >::type const_type;

#define BOOST_FUSION_ADT_ATTRIBUTE_GIVENTYPE(                                   \
    NAME_SEQ, ATTRIBUTE, ATTRIBUTE_TUPEL_SIZE, PREFIX)                          \
                                                                                \
    typedef BOOST_PP_TUPLE_ELEM(ATTRIBUTE_TUPEL_SIZE, 0, ATTRIBUTE) type;       \
    typedef BOOST_PP_TUPLE_ELEM(ATTRIBUTE_TUPEL_SIZE, 1, ATTRIBUTE) const_type;


#define BOOST_FUSION_ADAPT_ADT_C_BASE(                                          \
    TEMPLATE_PARAMS_SEQ,NAME_SEQ,I,PREFIX,                                      \
    ATTRIBUTE,ATTRIBUTE_TUPEL_SIZE, DEDUCE_TYPE)                                \
                                                                                \
    template<                                                                   \
        BOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS(TEMPLATE_PARAMS_SEQ)   \
    >                                                                           \
    struct access::adt_attribute_access<                                        \
        BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)                         \
      , I                                                                       \
    >                                                                           \
    {                                                                           \
                                                                                \
        BOOST_PP_IF(DEDUCE_TYPE,                                                \
            BOOST_FUSION_ADT_ATTRIBUTE_TYPEOF,                                  \
            BOOST_FUSION_ADT_ATTRIBUTE_GIVENTYPE                                \
            )(NAME_SEQ, ATTRIBUTE, ATTRIBUTE_TUPEL_SIZE, PREFIX)                \
                                                                                \
        template<class Val>                                                     \
        BOOST_FUSION_GPU_ENABLED                                                \
        static void                                                             \
        boost_fusion_adapt_adt_impl_set(                                        \
            BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)& obj,               \
            Val const& val)                                                     \
        {                                                                       \
           PREFIX() BOOST_FUSION_ADAPT_ADT_ATTRIBUTE_SETEXPR(ATTRIBUTE,         \
                ATTRIBUTE_TUPEL_SIZE, DEDUCE_TYPE);                             \
        }                                                                       \
                                                                                \
        BOOST_FUSION_GPU_ENABLED                                                \
        static type                                                             \
        boost_fusion_adapt_adt_impl_get(                                        \
            BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)& obj)               \
        {                                                                       \
            return PREFIX() BOOST_FUSION_ADAPT_ADT_ATTRIBUTE_GETEXPR(ATTRIBUTE, \
                ATTRIBUTE_TUPEL_SIZE, DEDUCE_TYPE);                             \
        }                                                                       \
                                                                                \
        BOOST_FUSION_GPU_ENABLED                                                \
        static const_type                                                       \
        boost_fusion_adapt_adt_impl_get(                                        \
            BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ) const& obj)         \
        {                                                                       \
            return PREFIX() BOOST_FUSION_ADAPT_ADT_ATTRIBUTE_GETEXPR(ATTRIBUTE, \
                ATTRIBUTE_TUPEL_SIZE, DEDUCE_TYPE);                             \
        }                                                                       \
    };                                                                          \
                                                                                \
    template<                                                                   \
        BOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS(TEMPLATE_PARAMS_SEQ)   \
    >                                                                           \
    struct adt_attribute_proxy<                                                 \
        BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)                         \
      , I                                                                       \
      , true                                                                    \
    >                                                                           \
    {                                                                           \
        typedef access::adt_attribute_access<                                   \
                BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)                 \
              , I                                                               \
            >::const_type type;                                                 \
                                                                                \
        BOOST_FUSION_GPU_ENABLED                                                \
        explicit                                                                \
        adt_attribute_proxy(                                                    \
            BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ) const& o)           \
          : obj(&o)                                                             \
        {}                                                                      \
                                                                                \
        BOOST_FUSION_GPU_ENABLED                                                \
        type get() const                                                        \
        {                                                                       \
            return access::adt_attribute_access<                                \
                BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)                 \
              , I                                                               \
            >::boost_fusion_adapt_adt_impl_get(*obj);                           \
        }                                                                       \
                                                                                \
        BOOST_FUSION_GPU_ENABLED                                                \
        operator type() const                                                   \
        {                                                                       \
            return get();                                                       \
        }                                                                       \
                                                                                \
        BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ) const* obj;             \
    };                                                                          \
                                                                                \
    template<                                                                   \
        BOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS(TEMPLATE_PARAMS_SEQ)   \
    >                                                                           \
    struct adt_attribute_proxy<                                                 \
        BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)                         \
      , I                                                                       \
      , false                                                                   \
    >                                                                           \
    {                                                                           \
        typedef access::adt_attribute_access<                                   \
                BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)                 \
              , I                                                               \
            >::type type;                                                       \
                                                                                \
        BOOST_FUSION_GPU_ENABLED                                                \
        explicit                                                                \
        adt_attribute_proxy(                                                    \
            BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)& o)                 \
          : obj(&o)                                                             \
        {}                                                                      \
                                                                                \
        template<class Val>                                                     \
        BOOST_FUSION_GPU_ENABLED                                                \
        adt_attribute_proxy&                                                    \
        operator=(Val const& val)                                               \
        {                                                                       \
            access::adt_attribute_access<                                       \
                BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)                 \
              , I                                                               \
            >::boost_fusion_adapt_adt_impl_set(*obj, val);                      \
            return *this;                                                       \
        }                                                                       \
                                                                                \
        BOOST_FUSION_GPU_ENABLED                                                \
        type get() const                                                        \
        {                                                                       \
            return access::adt_attribute_access<                                \
                BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)                 \
              , I                                                               \
            >::boost_fusion_adapt_adt_impl_get(*obj);                           \
        }                                                                       \
                                                                                \
        BOOST_FUSION_GPU_ENABLED                                                \
        operator type() const                                                   \
        {                                                                       \
            return get();                                                       \
        }                                                                       \
                                                                                \
        BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)* obj;                   \
    };                                                                          \
                                                                                \
    template<                                                                   \
        BOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS(TEMPLATE_PARAMS_SEQ)   \
    >                                                                           \
    struct access::struct_member<                                               \
        BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)                         \
      , I                                                                       \
    >                                                                           \
    {                                                                           \
        typedef \
            adt_attribute_proxy<                                                \
                          BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)       \
                        , I                                                     \
                        , false                                                 \
                      >::type lvalue;                                           \
                                                                                \
        BOOST_FUSION_ADAPT_STRUCT_MSVC_REDEFINE_TEMPLATE_PARAMS(                \
            TEMPLATE_PARAMS_SEQ)                                                \
                                                                                \
        typedef                                                                 \
            BOOST_PP_IF(                                                        \
                BOOST_PP_SEQ_HEAD(TEMPLATE_PARAMS_SEQ),                         \
                BOOST_FUSION_ADAPT_ADT_GET_IDENTITY_TEMPLATE_IMPL,              \
                BOOST_FUSION_ADAPT_ADT_GET_IDENTITY_NON_TEMPLATE_IMPL)(         \
                    TEMPLATE_PARAMS_SEQ)                                        \
        type;                                                                   \
                                                                                \
        template<typename Seq>                                                  \
        struct apply                                                            \
        {                                                                       \
            typedef                                                             \
                adt_attribute_proxy<                                            \
                    BOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)             \
                  , I                                                           \
                  , is_const<Seq>::value                                        \
                >                                                               \
            type;                                                               \
                                                                                \
            BOOST_FUSION_GPU_ENABLED                                            \
            static type                                                         \
            call(Seq& obj)                                                      \
            {                                                                   \
                return type(obj);                                               \
            }                                                                   \
        };                                                                      \
    };

#endif

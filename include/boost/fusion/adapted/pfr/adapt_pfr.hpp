/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_ADAPTED_STRUCT_ADAPT_PFR_HPP)
#define BOOST_FUSION_ADAPTED_STRUCT_ADAPT_PFR_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/adapted/pfr/detail/at_impl.hpp>
#include <boost/fusion/adapted/pfr/detail/begin_impl.hpp>
#include <boost/fusion/adapted/pfr/detail/category_of_impl.hpp>
#include <boost/fusion/adapted/pfr/detail/end_impl.hpp>
#include <boost/fusion/adapted/pfr/detail/is_sequence_impl.hpp>
#include <boost/fusion/adapted/pfr/detail/is_view_impl.hpp>
#include <boost/fusion/adapted/pfr/detail/size_impl.hpp>
#include <boost/fusion/adapted/pfr/detail/value_at_impl.hpp>
#include <boost/fusion/support/tag_of_fwd.hpp>

#define BOOST_FUSION_ADAPT_PFR(NAME)                                            \
                                                                                \
    namespace boost { namespace fusion {                                        \
        struct pfr_tag;                                                         \
        struct fusion_sequence_tag;                                             \
                                                                                \
        namespace traits                                                        \
        {                                                                       \
            template<>                                                          \
            struct tag_of<NAME>                                                 \
            {                                                                   \
                using type = pfr_tag;                                           \
            };                                                                  \
            template<>                                                          \
            struct tag_of<NAME const>                                           \
            {                                                                   \
                using type = pfr_tag;                                           \
            };                                                                  \
        }                                                                       \
    }}                                                                          \
                                                                                \
    namespace boost { namespace mpl                                             \
    {                                                                           \
        template<typename>                                                      \
        struct sequence_tag;                                                    \
                                                                                \
        template<>                                                              \
        struct sequence_tag<NAME>                                               \
        {                                                                       \
            using type = fusion::fusion_sequence_tag;                           \
        };                                                                      \
                                                                                \
        template<>                                                              \
        struct sequence_tag<NAME const>                                         \
        {                                                                       \
            using type = fusion::fusion_sequence_tag;                           \
        };                                                                      \
    }}                                                                          

#define BOOST_FUSION_ADAPT_TPL_PFR(NAME)                                        \
                                                                                \
    namespace boost { namespace fusion {                                        \
        struct pfr_tag;                                                         \
        struct fusion_sequence_tag;                                             \
                                                                                \
        namespace traits                                                        \
        {                                                                       \
            template<typename... Args>                                          \
            struct tag_of<NAME<Args...>>                                        \
            {                                                                   \
                using type = pfr_tag;                                           \
            };                                                                  \
            template<typename... Args>                                          \
            struct tag_of<NAME<Args...> const>                                  \
            {                                                                   \
                using type = pfr_tag;                                           \
            };                                                                  \
        }                                                                       \
    }}                                                                          \
                                                                                \
    namespace boost { namespace mpl                                             \
    {                                                                           \
        template<typename>                                                      \
        struct sequence_tag;                                                    \
                                                                                \
        template<typename... Args>                                              \
        struct sequence_tag<NAME<Args...>>                                      \
        {                                                                       \
            using type = fusion::fusion_sequence_tag;                           \
        };                                                                      \
                                                                                \
        template<typename... Args>                                              \
        struct sequence_tag<NAME<Args...> const>                                \
        {                                                                       \
            using type = fusion::fusion_sequence_tag;                           \
        };                                                                      \
    }}                                                                          

#endif

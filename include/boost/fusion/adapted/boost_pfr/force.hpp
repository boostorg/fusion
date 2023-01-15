/*=============================================================================
    Copyright (c) 2021-2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_BOOST_PFR_FORCE_HPP
#define BOOST_FUSION_ADAPTED_BOOST_PFR_FORCE_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/adapted/boost_pfr/detail/at_impl.hpp>
#include <boost/fusion/adapted/boost_pfr/detail/begin_impl.hpp>
#include <boost/fusion/adapted/boost_pfr/detail/category_of_impl.hpp>
#include <boost/fusion/adapted/boost_pfr/detail/end_impl.hpp>
#include <boost/fusion/adapted/boost_pfr/detail/is_sequence_impl.hpp>
#include <boost/fusion/adapted/boost_pfr/detail/is_view_impl.hpp>
#include <boost/fusion/adapted/boost_pfr/detail/size_impl.hpp>
#include <boost/fusion/adapted/boost_pfr/detail/value_at_impl.hpp>
#include <boost/pfr/traits.hpp>

namespace boost { namespace pfr {
  struct boost_fusion_tag;
}} // namespace boost::pfr

#define BOOST_FUSION_FORCE_PFR_REFLECTABLE(NAME)                                               \
    namespace boost { namespace pfr {                                                          \
        template<> struct is_reflectable<NAME, boost::pfr::boost_fusion_tag>                   \
                       : std::true_type                                                        \
                   {                                                                           \
                   };                                                                          \
    }}

#define BOOST_FUSION_FORCE_PFR_NONREFLECTABLE(NAME)                                            \
    namespace boost { namespace pfr {                                                          \
        template<> struct is_reflectable<NAME, boost::pfr::boost_fusion_tag>                   \
                       : std::false_type                                                       \
                   {                                                                           \
                   };                                                                          \
    }}

#define BOOST_FUSION_FORCE_PFR_REFLECTABLE_TPL(NAME)                                           \
    namespace boost { namespace pfr {                                                          \
        template<typename... Args>                                                             \
        struct is_reflectable<NAME<Args...>, boost::pfr::boost_fusion_tag>                     \
            : std::true_type                                                                   \
        {                                                                                      \
        };                                                                                     \
    }}

#define BOOST_FUSION_FORCE_PFR_NONREFLECTABLE_TPL(NAME)                                        \
    namespace boost { namespace pfr {                                                          \
        template<typename... Args>                                                             \
        struct is_reflectable<NAME<Args...>, boost::pfr::boost_fusion_tag>                     \
            : std::false_type                                                                  \
        {                                                                                      \
        };                                                                                     \
    }}

#endif //BOOST_FUSION_ADAPTED_BOOST_PFR_FORCE_HPP

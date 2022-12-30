/*=============================================================================
    Copyright (c) 2021-2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_BOOST_PFR_TAG_OF_FALLBACK_HPP
#define BOOST_FUSION_ADAPTED_BOOST_PFR_TAG_OF_FALLBACK_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/support/tag_of_fwd.hpp>
#include <boost/pfr/traits.hpp>
#include <type_traits>

namespace boost { namespace pfr {
  struct boost_fusion_tag;
}} // namespace boost::pfr

namespace boost { namespace fusion
{
    struct boost_pfr_tag;
    struct non_fusion_tag;
    struct fusion_sequence_tag;

    namespace detail
    {
        template <typename T>
        struct tag_of_fallback<T, std::enable_if_t<std::is_same<T, T>::value>>
        {
            static constexpr auto possible_pfr = boost::pfr::is_implicitly_reflectable<
                T, boost::pfr::boost_fusion_tag>::value;
            using type = std::conditional_t<(!std::is_array<T>::value && possible_pfr)
              , boost_pfr_tag
              , non_fusion_tag
            >;
        };
    }
}}

#endif //BOOST_FUSION_ADAPTED_BOOST_PFR_TAG_OF_FALLBACK_HPP


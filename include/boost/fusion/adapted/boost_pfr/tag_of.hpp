/*=============================================================================
    Copyright (c) 2021-2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_BOOST_PFR_TAG_OF_HPP
#define BOOST_FUSION_ADAPTED_BOOST_PFR_TAG_OF_HPP

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
    struct fusion_sequence_tag;

    namespace traits
    {
        template <typename T>
        struct tag_of<T, std::enable_if_t<boost::pfr::is_reflectable<
                             T, boost::pfr::boost_fusion_tag>::value>>
        {
            using type = boost_pfr_tag;
        };
    }
}}

#endif //BOOST_FUSION_ADAPTED_BOOST_PFR_TAG_OF_HPP


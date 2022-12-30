/*=============================================================================
    Copyright (c) 2021-2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_AT_IMPL_HPP
#define BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_AT_IMPL_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/pfr/core.hpp>
#include <utility> // for std::declval
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <type_traits> // for std::is_reference

namespace boost { namespace fusion
{
    struct boost_pfr_tag;

    namespace extension
    {
        template<typename Tag>
        struct at_impl;

        template<>
        struct at_impl<boost_pfr_tag>
        {
            template <typename Reflectable, typename N>
            struct apply
            {
                using type = decltype(boost::pfr::get<N::value>(
                    std::declval<Reflectable&>()));
                static_assert(std::is_reference<type>::value, "internal error");

                constexpr BOOST_FUSION_GPU_ENABLED
                static decltype(auto)
                call(Reflectable& seq) noexcept
                {
                    return boost::pfr::get<N::value>(seq);
                }
            };
        };
    }
}}

#endif //BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_AT_IMPL_HPP


/*=============================================================================
    Copyright (c) 2021-2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_BEGIN_IMPL_HPP
#define BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_BEGIN_IMPL_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/sequence/intrinsic/begin.hpp>
#include <boost/fusion/adapted/boost_pfr/boost_pfr_iterator.hpp>

namespace boost { namespace fusion
{
    struct boost_pfr_tag;

    namespace extension
    {
        template<typename Tag>
        struct begin_impl;

        template <>
        struct begin_impl<boost_pfr_tag>
        {
            template <typename Reflectable>
            struct apply
            {
                using type = boost_pfr_iterator<Reflectable, 0>;

                constexpr BOOST_FUSION_GPU_ENABLED
                static auto
                call(Reflectable& v) noexcept
                {
                    return type(v);
                }
            };
        };
    }
}}

#endif //BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_BEGIN_IMPL_HPP


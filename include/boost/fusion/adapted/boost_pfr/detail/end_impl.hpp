/*=============================================================================
    Copyright (c) 2021-2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_END_IMPL_HPP
#define BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_END_IMPL_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/adapted/boost_pfr/boost_pfr_iterator.hpp>
#include <boost/pfr/tuple_size.hpp>
#include <boost/fusion/sequence/intrinsic/end.hpp>

namespace boost { namespace fusion
{
    struct boost_pfr_tag;

    namespace extension
    {
        template<typename Tag>
        struct end_impl;

        template<>
        struct end_impl<boost_pfr_tag>
        {
            template <typename Reflectable>
            struct apply
            {
                static constexpr auto size = boost::pfr::tuple_size_v<Reflectable>;
                using type = boost_pfr_iterator<Reflectable, size>;

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

#endif //BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_END_IMPL_HPP


/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_PFR_FIELDS_VIEW_DISTANCE_IMPL_HPP_INCLUDED)
#define BOOST_FUSION_PFR_FIELDS_VIEW_DISTANCE_IMPL_HPP_INCLUDED

#include <boost/fusion/support/config.hpp>
#include <boost/mpl/int.hpp>

namespace boost { namespace fusion {
    struct pfr_fields_view_iterator_tag;

    namespace extension
    {
        template<typename>
        struct distance_impl;

        template<>
        struct distance_impl<pfr_fields_view_iterator_tag>
        {
            template <typename First, typename Last>
            struct apply
            {
                using type = mpl::int_<Last::index::value-First::index::value>;

                constexpr BOOST_FUSION_GPU_ENABLED
                static auto
                call(First const&, Last const&)
                {
                    return type();
                }
            };
        };
    }
}}

#endif
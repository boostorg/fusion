/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_PFR_FIELDS_VIEW_AT_IMPL_HPP_INCLUDED)
#define BOOST_FUSION_PFR_FIELDS_VIEW_AT_IMPL_HPP_INCLUDED

#include <boost/fusion/support/config.hpp>
#include <boost/pfr/core.hpp>
#include <utility> // for std::declval

namespace boost { namespace fusion {
    struct pfr_fields_view_tag;

    namespace extension
    {
        template<typename Tag>
        struct at_impl;

        template <>
        struct at_impl<pfr_fields_view_tag>
        {
            template <typename Sequence, typename N>
            struct apply
            {
                using type = decltype(boost::pfr::get<N::value>(std::declval<Sequence>().agg));

                constexpr BOOST_FUSION_GPU_ENABLED
                static decltype(auto)
                call(Sequence& v)
                {
                    return boost::pfr::get<N::value>(v.agg);
                }
            };
        };
    }
}}

#endif
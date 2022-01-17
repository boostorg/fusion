/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(FUSION_PFR_FIELDS_54763465_8735)
#define FUSION_PFR_FIELDS_54763465_8735

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/view/pfr_fields_view/pfr_fields_view.hpp>

namespace boost { namespace fusion { namespace result_of
{
    template<typename Aggregate>
    struct pfr_fields
    {
        typedef pfr_fields_view<Aggregate> type;
    };
}}}

namespace boost { namespace fusion
{
    template <typename Aggregate>
    constexpr BOOST_FUSION_GPU_ENABLED
    auto pfr_fields(Aggregate& view)
    {
        using type = typename result_of::pfr_fields<Aggregate>::type;
        return type(view);
    }

    template <typename Aggregate>
    constexpr BOOST_FUSION_GPU_ENABLED
    auto pfr_fields(Aggregate const& view)
    {
        using type = typename result_of::pfr_fields<Aggregate const>::type;
        return type(view);
    }
}}

#endif
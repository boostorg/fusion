/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(FUSION_PFR_98457698_34587)
#define FUSION_PFR_98457698_34587

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/view/pfr_view/pfr_view.hpp>

namespace boost { namespace fusion { namespace result_of
{
    template<typename T>
    struct pfr
    {
        typedef pfr_view<T> type;
    };
}}}

namespace boost { namespace fusion
{
    template <typename T>
    constexpr BOOST_FUSION_GPU_ENABLED
    auto pfr(T& view)
    {
        using type = typename result_of::pfr<T>::type;
        return type(view);
    }

    template <typename T>
    constexpr BOOST_FUSION_GPU_ENABLED
    auto pfr(T const& view)
    {
        using type = typename result_of::pfr<T const>::type;
        return type(view);
    }
}}

#endif

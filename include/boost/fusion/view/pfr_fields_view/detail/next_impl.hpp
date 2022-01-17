/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_PFR_FIELDS_VIEW_NEXT_IMPL_HPP_INCLUDED)
#define BOOST_FUSION_PFR_FIELDS_VIEW_NEXT_IMPL_HPP_INCLUDED

#include <boost/fusion/support/config.hpp>
#include <boost/mpl/int.hpp>

namespace boost { namespace fusion {
    struct pfr_fields_view_iterator_tag;

    template<typename Aggregate, typename Pos>
    struct pfr_fields_view_iterator;

    namespace extension
    {
        template<typename>
        struct next_impl;

        template<>
        struct next_impl<pfr_fields_view_iterator_tag>
        {
            template <typename Iterator>
            struct apply
            {
                using type = pfr_fields_view_iterator<
                    typename Iterator::aggregate_type
                  , mpl::int_<Iterator::index::value + 1>
                >;

                constexpr BOOST_FUSION_GPU_ENABLED
                static auto
                call(Iterator const& it)
                {
                    return type(it.agg);
                }
            };
        };
    }
}}

#endif
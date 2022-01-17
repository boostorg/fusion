/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_PFR_FIELDS_VIEW_DEREF_IMPL_HPP_INCLUDED)
#define BOOST_FUSION_PFR_FIELDS_VIEW_DEREF_IMPL_HPP_INCLUDED

#include <boost/fusion/support/config.hpp>
#include <boost/pfr/core.hpp>
#include <utility> // for std::declval

namespace boost { namespace fusion {
    struct pfr_fields_view_iterator_tag;

    namespace extension
    {
        template<typename>
        struct deref_impl;

        template<>
        struct deref_impl<pfr_fields_view_iterator_tag>
        {
            template <typename Iterator>
            struct apply
            {
                using type = decltype(
                    boost::pfr::get<Iterator::index::value>(
                        std::declval<Iterator>().agg
                    )
                );

                constexpr BOOST_FUSION_GPU_ENABLED
                static decltype(auto)
                call(Iterator const& iter)
                {
                    return boost::pfr::get<Iterator::index::value>(iter.agg);
                }
            };
        };
    }
}}

#endif
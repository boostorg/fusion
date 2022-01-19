/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_PFR_FIELDS_VIEW_DEREF_IMPL_HPP_INCLUDED)
#define BOOST_FUSION_PFR_FIELDS_VIEW_DEREF_IMPL_HPP_INCLUDED

#include <boost/fusion/support/config.hpp>
#include <boost/pfr/core.hpp>
#include <type_traits> // for std::is_const, std::remove_const
#include <boost/mpl/if.hpp>
#include <boost/fusion/support/detail/access.hpp>

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
                using aggregate_type = typename std::remove_const<typename Iterator::aggregate_type>::type;
                using index = typename Iterator::index;
                using element = typename boost::pfr::tuple_element<index::value, aggregate_type>::type;
                using type = typename
                    mpl::if_<
                        std::is_const<typename Iterator::aggregate_type>
                      , typename fusion::detail::cref_result<element>::type
                      , typename fusion::detail::ref_result<element>::type
                    >::type
                ;

                constexpr BOOST_FUSION_GPU_ENABLED
                static type
                call(Iterator const& iter)
                {
                    return boost::pfr::get<Iterator::index::value>(iter.agg);
                }
            };
        };
    }
}}

#endif
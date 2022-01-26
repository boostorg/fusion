/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_PFR_FIELDS_VIEW_AT_IMPL_HPP_INCLUDED)
#define BOOST_FUSION_PFR_FIELDS_VIEW_AT_IMPL_HPP_INCLUDED

#include <boost/fusion/support/config.hpp>
#include <boost/pfr/core.hpp>
#include <type_traits> // for std::is_const, std::remove_const_t
#include <boost/mp11/utility.hpp>
#include <boost/fusion/support/detail/access.hpp>

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
                using aggregate_type = std::remove_const_t<typename Sequence::aggregate_type>;
                using element = boost::pfr::tuple_element_t<N::value, aggregate_type>;

                using type = mp11::mp_if<
                    std::is_const<typename Sequence::aggregate_type>
                  , typename fusion::detail::cref_result<element>::type
                  , typename fusion::detail::ref_result<element>::type
                >;

                constexpr BOOST_FUSION_GPU_ENABLED
                static type
                call(Sequence& v)
                {
                    return boost::pfr::get<N::value>(v.agg);
                }
            };
        };
    }
}}

#endif
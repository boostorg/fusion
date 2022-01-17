/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_PFR_FIELDS_VIEW_VALUE_AT_IMPL_HPP_INCLUDED)
#define BOOST_FUSION_PFR_FIELDS_VIEW_VALUE_AT_IMPL_HPP_INCLUDED

#include <boost/fusion/support/config.hpp>
#include <boost/pfr/core.hpp>
#include <type_traits> // for std::remove_const_t

namespace boost { namespace fusion {
    struct pfr_fields_view_tag;

    namespace extension
    {
        template<typename T>
        struct value_at_impl;

        template <>
        struct value_at_impl<pfr_fields_view_tag>
        {
            template <typename Sequence, typename N>
            struct apply : boost::pfr::tuple_element<N::value, 
                    std::remove_const_t<typename Sequence::aggregate_type>> {};
        };
    }
}}

#endif
/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_PFR_FIELDS_VIEW_VALUE_OF_IMPL_HPP_INCLUDED)
#define BOOST_FUSION_PFR_FIELDS_VIEW_VALUE_OF_IMPL_HPP_INCLUDED

#include <boost/fusion/support/config.hpp>
#include <boost/pfr/core.hpp>
#include <type_traits> // for std::remove_const_t

namespace boost { namespace fusion {
    struct pfr_fields_view_iterator_tag;

    namespace extension
    {
        template<typename>
        struct value_of_impl;

        template<>
        struct value_of_impl<pfr_fields_view_iterator_tag>
        {
            template <typename Iterator>
            struct apply : boost::pfr::tuple_element<Iterator::index::value,
                    std::remove_const_t<typename Iterator::aggregate_type>> {};
        };
    }
}}

#endif
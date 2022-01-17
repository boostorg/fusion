/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_PFR_FIELDS_VIEW_VALUE_OF_DATA_IMPL_HPP_INCLUDED)
#define BOOST_FUSION_PFR_FIELDS_VIEW_VALUE_OF_DATA_IMPL_HPP_INCLUDED

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/view/pfr_fields_view/detail/value_of_impl.hpp>

namespace boost { namespace fusion {
    struct pfr_fields_view_iterator_tag;

    namespace extension
    {
        template<typename>
        struct value_of_data_impl;

        template<>
        struct value_of_data_impl<pfr_fields_view_iterator_tag>
            : value_of_impl<pfr_fields_view_iterator_tag>
        {
        };
    }
}}

#endif
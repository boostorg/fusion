/*=============================================================================
    Copyright (c) 2021 Denis Mikhailov

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_PFR_DETAIL_VALUE_AT_IMPL_HPP
#define BOOST_FUSION_ADAPTED_PFR_DETAIL_VALUE_AT_IMPL_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/pfr/core.hpp>

namespace boost { namespace fusion
{
    struct pfr_tag;

    namespace extension
    {
        template<typename T>
        struct value_at_impl;

        template<>
        struct value_at_impl<pfr_tag>
        {
            template <typename Sequence, typename N>
            struct apply : boost::pfr::tuple_element<N::value, Sequence> {};
        };
    }
}}

#endif //BOOST_FUSION_ADAPTED_PFR_DETAIL_VALUE_AT_IMPL_HPP

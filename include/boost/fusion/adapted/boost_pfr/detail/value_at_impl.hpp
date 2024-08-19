/*=============================================================================
    Copyright (c) 2021-2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_VALUE_AT_IMPL_HPP
#define BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_VALUE_AT_IMPL_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/pfr/core.hpp>
#include <boost/fusion/sequence/intrinsic/value_at.hpp>
#include <type_traits> // for std::remove_const_t

namespace boost { namespace fusion
{
    struct boost_pfr_tag;

    namespace extension
    {
        template<typename Tag>
        struct value_at_impl;

        template<>
        struct value_at_impl<boost_pfr_tag>
        {
            template <typename Reflectable, typename N>
            struct apply : boost::pfr::tuple_element<N::value,
                std::remove_const_t<Reflectable>> {};
        };
    }
}}

#endif //BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_VALUE_AT_IMPL_HPP

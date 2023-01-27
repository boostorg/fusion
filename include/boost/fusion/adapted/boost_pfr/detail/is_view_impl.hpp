/*=============================================================================
    Copyright (c) 2021-2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_IS_VIEW_IMPL_HPP
#define BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_IS_VIEW_IMPL_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/pfr/traits.hpp>

namespace boost { namespace fusion
{
    struct boost_pfr_tag;

    namespace extension
    {
        template<typename Tag>
        struct is_view_impl;

        // FIXME replace like this after merging of https://github.com/boostorg/pfr/pull/112
        // template<>
        // struct is_view_impl<boost_pfr_tag>
        // {
        //     template<typename Reflectable>
        //     struct apply : boost::pfr::is_view<Reflectable> {};
        // };
        
        template<>
        struct is_view_impl<boost_pfr_tag>
        {
            template<typename Reflectable>
            struct apply : mpl::false_ {};
        };
    }
}}

#endif //BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_IS_VIEW_IMPL_HPP

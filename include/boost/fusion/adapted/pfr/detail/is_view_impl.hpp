/*=============================================================================
    Copyright (c) 2021 Denis Mikhailov

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_PFR_DETAIL_IS_VIEW_IMPL_HPP
#define BOOST_FUSION_ADAPTED_PFR_DETAIL_IS_VIEW_IMPL_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/mpl/bool.hpp>

namespace boost { namespace fusion
{
    struct pfr_tag;

    namespace extension
    {
        template<typename Tag>
        struct is_view_impl;

        template<>
        struct is_view_impl<pfr_tag>
        {
            template<typename T>
            struct apply : mpl::false_ {};
        };
    }
}}

#endif //BOOST_FUSION_ADAPTED_PFR_DETAIL_IS_VIEW_IMPL_HPP

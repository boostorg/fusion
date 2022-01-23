/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_ADAPTED_PFR_DETAIL_VIEW_IMPL_HPP)
#define BOOST_FUSION_ADAPTED_PFR_DETAIL_VIEW_IMPL_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/view/pfr_fields_view.hpp>
#include <boost/fusion/sequence/intrinsic/size.hpp>

namespace boost { namespace fusion
{
    struct pfr_tag;

    namespace extension
    {
        template<typename T>
        struct size_impl;

        template<>
        struct size_impl<pfr_tag>
        {
            template <typename Aggregate>
            struct apply : result_of::size< pfr_fields_view<Aggregate> >
            {
            };
        };
    }
}}

#endif

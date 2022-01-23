/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_ADAPTED_PFR_DETAIL_END_IMPL_HPP)
#define BOOST_FUSION_ADAPTED_PFR_DETAIL_END_IMPL_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/view/pfr_fields_view.hpp>
#include <boost/fusion/algorithm/auxiliary/pfr_fields.hpp>
#include <boost/fusion/sequence/intrinsic/end.hpp>

namespace boost { namespace fusion
{
    struct pfr_tag;

    namespace extension
    {
        template<typename T>
        struct end_impl;

        template<>
        struct end_impl<pfr_tag>
        {
            template <typename Aggregate>
            struct apply
            {
                using type = typename result_of::end< pfr_fields_view<Aggregate> >::type;

                constexpr BOOST_FUSION_GPU_ENABLED
                static type
                call(Aggregate& seq)
                {
                    return end(pfr_fields(seq));
                }
            };
        };
    }
}}

#endif

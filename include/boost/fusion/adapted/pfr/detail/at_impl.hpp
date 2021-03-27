/*=============================================================================
    Copyright (c) 2021 Denis Mikhailov

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_PFR_DETAIL_AT_IMPL_HPP
#define BOOST_FUSION_ADAPTED_PFR_DETAIL_AT_IMPL_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/pfr.hpp>
#include <utility>
#include <boost/mpl/if.hpp>
#include <boost/fusion/support/detail/access.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/is_const.hpp>

namespace boost { namespace fusion
{
    struct pfr_tag;

    namespace extension
    {
        template<typename T>
        struct at_impl;

        template<>
        struct at_impl<pfr_tag>
        {
            template <typename Sequence, typename N>
            struct apply
            {
                typedef typename remove_const<Sequence>::type seq_type;
                typedef typename boost::pfr::tuple_element<N::value, seq_type>::type element;

                typedef typename
                mpl::if_<
                        is_const<Sequence>
                      , typename fusion::detail::cref_result<element>::type
                      , typename fusion::detail::ref_result<element>::type
                      >::type
                type;

                BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
                static type
                call(Sequence& seq)
                {
                    return boost::pfr::get<N::value>(seq);
                }
            };
        };
    }
}}

#endif //BOOST_FUSION_ADAPTED_PFR_DETAIL_AT_IMPL_HPP

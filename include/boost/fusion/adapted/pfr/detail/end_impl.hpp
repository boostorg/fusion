/*=============================================================================
    Copyright (c) 2021 Denis Mikhailov

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_PFR_DETAIL_END_IMPL_HPP
#define BOOST_FUSION_ADAPTED_PFR_DETAIL_END_IMPL_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/adapted/pfr/pfr_iterator.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/pfr.hpp>

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
            template <typename Sequence>
            struct apply
            {
                typedef typename remove_const<Sequence>::type seq_type;
                static int const size = boost::pfr::tuple_size<seq_type>::value;
                typedef pfr_iterator<Sequence, size> type;

                BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
                static type
                call(Sequence& v)
                {
                    return type(v);
                }
            };
        };
    }
}}

#endif //BOOST_FUSION_ADAPTED_PFR_DETAIL_END_IMPL_HPP

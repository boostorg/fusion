/*=============================================================================
    Copyright (c) 2021-2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_VIEW_IMPL_HPP
#define BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_VIEW_IMPL_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/pfr/tuple_size.hpp>
#include <boost/mpl/int.hpp>
#include <boost/fusion/sequence/intrinsic/size.hpp>

namespace boost { namespace fusion
{
    struct boost_pfr_tag;

    namespace extension
    {
        template<typename Tag>
        struct size_impl;

        template<>
        struct size_impl<boost_pfr_tag>
        {
            template <typename Reflectable>
            struct apply : mpl::int_<
                boost::pfr::tuple_size_v<Reflectable>
            > {};
        };
    }
}}

#endif //BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_VIEW_IMPL_HPP


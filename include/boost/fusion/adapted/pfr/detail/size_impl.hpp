/*=============================================================================
    Copyright (c) 2021 Denis Mikhailov

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_PFR_DETAIL_VIEW_IMPL_HPP
#define BOOST_FUSION_ADAPTED_PFR_DETAIL_VIEW_IMPL_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/pfr/tuple_size.hpp>
#include <boost/mpl/int.hpp>
#include <boost/type_traits/remove_const.hpp>

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
            template <typename Sequence>
            struct apply :
                    mpl::int_<boost::pfr::tuple_size<
                            typename remove_const<Sequence>::type>::value
                    >
            {};
        };
    }
}}

#endif //BOOST_FUSION_ADAPTED_PFR_DETAIL_VIEW_IMPL_HPP

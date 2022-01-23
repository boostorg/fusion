/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_ADAPTED_PFR_DETAIL_CATEGORY_OF_IMPL_HPP)
#define BOOST_FUSION_ADAPTED_PFR_DETAIL_CATEGORY_OF_IMPL_HPP

#include <boost/fusion/support/config.hpp>

namespace boost { namespace fusion
{
    struct pfr_tag;
    struct random_access_traversal_tag;

    namespace extension
    {
        template<typename T>
        struct category_of_impl;

        template<>
        struct category_of_impl<pfr_tag>
        {
            template<typename T>
            struct apply
            {
                using type = random_access_traversal_tag;
            };
        };
    }
}}

#endif

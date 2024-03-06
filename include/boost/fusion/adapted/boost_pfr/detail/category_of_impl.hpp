/*=============================================================================
    Copyright (c) 2021-2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_CATEGORY_OF_IMPL_HPP
#define BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_CATEGORY_OF_IMPL_HPP

#include <boost/mpl/identity.hpp>

namespace boost { namespace fusion
{
    struct boost_pfr_tag;
    struct random_access_traversal_tag;

    namespace extension
    {
        template<typename Tag>
        struct category_of_impl;

        template<>
        struct category_of_impl<boost_pfr_tag>
        {
            template<typename Reflectable>
            struct apply : mpl::identity<random_access_traversal_tag> {};
        };
    }
}}

#endif //BOOST_FUSION_ADAPTED_BOOST_PFR_DETAIL_CATEGORY_OF_IMPL_HPP



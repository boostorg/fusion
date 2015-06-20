/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2011 Brandon Kohn

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(BOOST_FUSION_MAP_DETAIL_VALUE_AT_IMPL_HPP)
#define BOOST_FUSION_MAP_DETAIL_VALUE_AT_IMPL_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/support/tag_of.hpp>

namespace boost { namespace fusion
{
    struct map_tag;

    namespace extension
    {
        template <typename Tag>
        struct value_at_impl;

        template <>
        struct value_at_impl<map_tag>
        {
            template <typename Sequence, typename N>
            struct apply
            {
                typedef typename
                    traits::tag_of<typename Sequence::storage_type>::type
                tag;

                typedef typename
                    value_at_impl<tag>
                      ::template apply<typename Sequence::storage_type, N>::type
                type;
            };
        };
    }
}}

#endif //BOOST_FUSION_MAP_DETAIL_VALUE_AT_IMPL_HPP

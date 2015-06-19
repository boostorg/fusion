/*=============================================================================
    Copyright (c) 2014 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef FUSION_VALUE_AT_IMPL_16122014_1641
#define FUSION_VALUE_AT_IMPL_16122014_1641

#include <boost/config.hpp>
#include <boost/fusion/support/config.hpp>
#include <boost/fusion/container/vector/detail/config.hpp>

///////////////////////////////////////////////////////////////////////////////
// Without variadics, we will use the PP version
///////////////////////////////////////////////////////////////////////////////
#if !defined(BOOST_FUSION_HAS_VARIADIC_VECTOR)
# include <boost/fusion/container/vector/detail/cpp03/value_at_impl.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 interface
///////////////////////////////////////////////////////////////////////////////
#include <cstddef>
#include <boost/fusion/container/vector/vector_fwd.hpp>

namespace boost { namespace fusion
{
    struct vector_tag;

    namespace vector_detail
    {
        template <typename I, typename ...T>
        struct vector_data;
    }

    namespace extension
    {
        template <typename Tag>
        struct value_at_impl;

        template <>
        struct value_at_impl<vector_tag>
        {
            template <typename V, std::size_t N>
            struct apply_impl;

            template <typename H, typename ...T>
            struct apply_impl<vector<H, T...>, 0>
            {
                typedef H type;
            };

            template <typename H, typename ...T, std::size_t N>
            struct apply_impl<vector<H, T...>, N>
                : apply_impl<vector<T...>, N - 1>
            {};

            template <typename Sequence, typename N>
            struct apply : apply_impl<typename Sequence::type_sequence, N::value>
            {};
        };
    }
}}

#endif
#endif


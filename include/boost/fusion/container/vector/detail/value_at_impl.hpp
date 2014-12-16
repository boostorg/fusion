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

namespace boost { namespace fusion
{
    struct vector_tag;

    namespace vector_detail
    {
        template <std::size_t I, typename... T>
        struct data;
    }

    namespace extension
    {
        template <typename Tag>
        struct value_at_impl;

        template <>
        struct value_at_impl<vector_tag>
        {
            template <typename Data, std::size_t N>
            struct apply_impl : apply_impl<typename Data::base, N>
            {};

            template <typename T, typename ...Tail, std::size_t N>
            struct apply_impl<vector_detail::data<N, T, Tail...>, N>
            {
                typedef T type;
            };

            template <typename Sequence, typename N>
            struct apply : apply_impl<typename Sequence::data, N::value>
            {};
        };
    }
}}

#endif
#endif


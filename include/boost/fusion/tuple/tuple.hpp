/*=============================================================================
    Copyright (c) 2014 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef FUSION_TUPLE_14122014_0102
#define FUSION_TUPLE_14122014_0102

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/tuple/tuple_fwd.hpp>

///////////////////////////////////////////////////////////////////////////////
// With no variadics, we will use the C++03 version
///////////////////////////////////////////////////////////////////////////////
#if !defined(BOOST_FUSION_HAS_VARIADIC_TUPLE)
# include <boost/fusion/tuple/detail/tuple.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 interface
///////////////////////////////////////////////////////////////////////////////
#include <boost/fusion/support/detail/access.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/fusion/sequence/intrinsic/size.hpp>
#include <boost/fusion/sequence/intrinsic/value_at.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/sequence/comparison.hpp>
#include <boost/fusion/sequence/io.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/config/no_tr1/utility.hpp>

namespace boost { namespace fusion
{
    template <>
    struct tuple<> : vector<>
    {
        typedef vector<> base_type;

        BOOST_FUSION_GPU_ENABLED tuple()
            : base_type() {}

        BOOST_FUSION_GPU_ENABLED tuple(tuple const& rhs)
            : base_type(rhs) {}

        BOOST_FUSION_GPU_ENABLED
        tuple& operator=(tuple const& rhs)
        {
            base_type::operator=(rhs);
            return *this;
        }
    };

    template <typename ...T>
    struct tuple : vector<T...>
    {
        typedef vector<T...> base_type;

        BOOST_FUSION_GPU_ENABLED tuple()
            : base_type() {}

        BOOST_FUSION_GPU_ENABLED tuple(tuple const& rhs)
            : base_type(rhs) {}

        template <typename U1, typename U2>
        BOOST_FUSION_GPU_ENABLED
        tuple(std::pair<U1, U2> const& rhs)
            : base_type(rhs) {}

        BOOST_FUSION_GPU_ENABLED
        explicit
        tuple(typename detail::call_param<T>::type... arg)
            : base_type(arg...) {}

        template <typename ...U>
        BOOST_FUSION_GPU_ENABLED
        tuple(tuple<U...> const& rhs)
            : base_type(rhs) {}

        template <typename ...U>
        BOOST_FUSION_GPU_ENABLED
        tuple& operator=(tuple<U...> const& rhs)
        {
            base_type::operator=(rhs);
            return *this;
        }

        template <typename U>
        BOOST_FUSION_GPU_ENABLED
        tuple& operator=(U const& rhs)
        {
            base_type::operator=(rhs);
            return *this;
        }

        BOOST_FUSION_GPU_ENABLED
        tuple& operator=(tuple const& rhs)
        {
            base_type::operator=(rhs);
            return *this;
        }

        template <typename U1, typename U2>
        BOOST_FUSION_GPU_ENABLED
        tuple& operator=(std::pair<U1, U2> const& rhs)
        {
            base_type::operator=(rhs);
            return *this;
        }
    };

    template <typename Tuple>
    struct tuple_size : result_of::size<Tuple> {};

    template <int N, typename Tuple>
    struct tuple_element : result_of::value_at_c<Tuple, N> {};

    template <int N, typename Tuple>
    BOOST_FUSION_GPU_ENABLED
    inline typename
        lazy_disable_if<
            is_const<Tuple>
          , result_of::at_c<Tuple, N>
        >::type
    get(Tuple& tup)
    {
        return at_c<N>(tup);
    }

    template <int N, typename Tuple>
    BOOST_FUSION_GPU_ENABLED
    inline typename result_of::at_c<Tuple const, N>::type
    get(Tuple const& tup)
    {
        return at_c<N>(tup);
    }
}}

#endif
#endif


/*=============================================================================
    Copyright (c) 2014 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef FUSION_MAKE_TUPLE_14122014_0048
#define FUSION_MAKE_TUPLE_14122014_0048

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/tuple/tuple_fwd.hpp>

///////////////////////////////////////////////////////////////////////////////
// With no variadics, we will use the C++03 version
///////////////////////////////////////////////////////////////////////////////
#if !defined(BOOST_FUSION_HAS_VARIADIC_TUPLE)
# include <boost/fusion/tuple/detail/make_tuple.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 interface
///////////////////////////////////////////////////////////////////////////////
#include <boost/fusion/support/detail/as_fusion_element.hpp>
#include <boost/fusion/tuple/tuple.hpp>

namespace boost { namespace fusion
{
    BOOST_FUSION_GPU_ENABLED inline tuple<>
    make_tuple()
    {
        return tuple<>();
    }

    template <typename ...T>
    BOOST_FUSION_GPU_ENABLED
    inline tuple<typename detail::as_fusion_element<T>::type...>
    make_tuple(T const&... arg)
    {
        return tuple<typename detail::as_fusion_element<T>::type...>(arg...);
    }
}}

#endif
#endif


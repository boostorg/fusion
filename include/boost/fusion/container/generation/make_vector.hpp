/*=============================================================================
    Copyright (c) 2014 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef FUSION_MAKE_VECTOR_11112014_2252
#define FUSION_MAKE_VECTOR_11112014_2252

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/container/vector/vector.hpp>

#if !defined(BOOST_FUSION_HAS_VARIADIC_VECTOR)
# include <boost/fusion/container/generation/detail/pp_make_vector.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 variadic interface
///////////////////////////////////////////////////////////////////////////////

#include <boost/fusion/support/detail/as_fusion_element.hpp>

namespace boost { namespace fusion
{
    namespace result_of
    {
        template <typename ...T>
        struct make_vector
        {
            // make `make_vector<T..., void_...>' into `make_vector<T...>'
            template <typename, typename...> struct trim_void;

            template <typename... U>
            struct trim_void<vector<U...> >
            {
                typedef vector<numbered_vector_tag<sizeof...(U)>, U...> type;
            };

            template <typename... U, typename... Tail>
            struct trim_void<vector<U...>, void_, Tail...>
                : trim_void<vector<U...> > { };

            template <typename... U, typename Head, typename... Tail>
            struct trim_void<vector<U...>, Head, Tail...>
                : trim_void<vector<U..., Head>, Tail...> { };

            typedef
                typename trim_void<
                    vector<>
                  , typename detail::as_fusion_element<T>::type...
                >::type
            type;
        };
    }

    template <typename ...T>
    BOOST_FUSION_GPU_ENABLED
    inline typename result_of::make_vector<T...>::type
    make_vector(T const&... arg)
    {
        return typename result_of::make_vector<T...>::type(arg...);
    }
 }}


#endif
#endif


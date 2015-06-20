/*=============================================================================
    Copyright (c) 2014 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef FUSION_AS_SET_11062014_2121
#define FUSION_AS_SET_11062014_2121

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/container/set/set_fwd.hpp>

///////////////////////////////////////////////////////////////////////////////
// Without variadics, we will use the PP version
///////////////////////////////////////////////////////////////////////////////
#if !defined(BOOST_FUSION_HAS_VARIADIC_SET)
# include <boost/fusion/container/set/detail/cpp03/as_set.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 interface
///////////////////////////////////////////////////////////////////////////////
#include <boost/fusion/support/detail/integer_sequence.hpp>
#include <boost/fusion/container/set/set.hpp>
#include <boost/fusion/iterator/value_of.hpp>
#include <boost/fusion/iterator/deref.hpp>
#include <boost/fusion/iterator/advance.hpp>
#include <cstddef>

namespace boost { namespace fusion { namespace detail
{
BOOST_FUSION_BARRIER_BEGIN

    template <int size
#if BOOST_WORKAROUND(BOOST_MSVC, BOOST_TESTED_AT(1800))
            , typename = typename make_integer_sequence<int, size>::type>
#else
            , typename = typename make_integer_sequence<std::size_t, size>::type>
#endif
    struct as_set;

#if BOOST_WORKAROUND(BOOST_MSVC, BOOST_TESTED_AT(1800))
    template <int size, int ...Indices>
    struct as_set<size, integer_sequence<int, Indices...> >
#else
    template <int size, std::size_t ...Indices>
    struct as_set<size, integer_sequence<std::size_t, Indices...> >
#endif
    {
        template <typename I>
        struct apply
        {
            typedef set<
                typename result_of::value_of<
                    typename result_of::advance_c<I, Indices>::type
                >::type...
            > type;
        };

        template <typename Iterator>
        BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        static typename apply<Iterator>::type
        call(Iterator const& i)
        {
            typedef apply<Iterator> gen;
            typedef typename gen::type result;
            return result(*advance_c<Indices>(i)...);
        }
    };

BOOST_FUSION_BARRIER_END
}}}

#endif
#endif


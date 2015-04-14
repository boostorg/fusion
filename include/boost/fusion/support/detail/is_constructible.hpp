/*=============================================================================
    Copyright (c) 2014 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_FUSION_SUPPORT_DETAIL_IS_CONSTRUCTIBLE_16122014_1510
#define BOOST_FUSION_SUPPORT_DETAIL_IS_CONSTRUCTIBLE_16122014_1510

#include <boost/config.hpp>
#include <boost/fusion/support/config.hpp>
#include <boost/utility/declval.hpp>
#include <cstddef>

namespace boost { namespace fusion { namespace detail
{

    template <typename T, typename ...A>
    struct is_constructible
    {
        typedef char yes_type;
        struct no_type { char xx[2]; };

        template <std::size_t>
        struct wrap
        {
            wrap(int);
        };

// BOOST_WORKAROUND doesn't work with BOOST_CLANG.
// Also __clang_*__ don't work properly since Apple Clang says 5(6).x.y even
// based on LLVM 3.x.
#if !defined(BOOST_CLANG)
        template <typename T_, typename ...A_>
        BOOST_FUSION_GPU_ENABLED
        static yes_type
        check(wrap<sizeof(T_(boost::declval<A_>()...))>);
#else
        template <typename T_, typename ...A_>
        BOOST_FUSION_GPU_ENABLED
        static yes_type
        check(T_ const& = T_(boost::declval<A_>()...));
#endif

        template <typename, typename ...>
        BOOST_FUSION_GPU_ENABLED
        static no_type
        check(...);

        typedef is_constructible type;
        BOOST_STATIC_CONSTANT(bool, value = sizeof(yes_type) == sizeof(check<T, A...>(0)));
    };

}}}

#endif


/*=============================================================================
    Copyright (c) 2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_FUSION_SUPPORT_DETAIL_PROPAGATE_TRIVIALNESS
#define BOOST_FUSION_SUPPORT_DETAIL_PROPAGATE_TRIVIALNESS

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/support/detail/and.hpp>
#include <boost/fusion/support/detail/is_trivially_copyable.hpp>
#include <boost/mpl/if.hpp>

namespace boost { namespace fusion { namespace detail
{

struct trivial_base { };

struct non_trivial_base
{
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    BOOST_DEFAULTED_FUNCTION(non_trivial_base(), {})

    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    non_trivial_base(non_trivial_base const&) BOOST_NOEXCEPT { }
};

template <typename... T>
struct propagate_trivialness
  : mpl::if_c<and_<is_trivially_copyable<T>...>::value
      , trivial_base
      , non_trivial_base
    >::type
{ };

}}} // namespace boost::fusion::detail

#endif


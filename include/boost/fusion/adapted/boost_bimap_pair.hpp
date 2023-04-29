/*============================================================================
    Copyright (c) 2013-2018 Cromwell D. Enage

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/
#if !defined(BOOST_FUSION_ADAPTED_BOOST_BIMAP_PAIR_HPP)
#define BOOST_FUSION_ADAPTED_BOOST_BIMAP_PAIR_HPP

#include <boost/bimap/tags/support/default_tagged.hpp>
#include <boost/bimap/relation/member_at.hpp>

namespace boost { namespace fusion { namespace detail { namespace bimap_pair
{
    template <typename T>
    struct first_type
    {
        typedef typename ::boost::bimaps::tags::support::default_tagged<
            T
          , ::boost::bimaps::relation::member_at::left
        >::type::value_type type;
    };

    template <typename T>
    struct second_type
    {
        typedef typename ::boost::bimaps::tags::support::default_tagged<
            T
          , ::boost::bimaps::relation::member_at::right
        >::type::value_type type;
    };
}}}}

#include <boost/bimap/relation/structured_pair.hpp>
#include <boost/fusion/adapted/struct/adapt_struct.hpp>

BOOST_FUSION_ADAPT_TPL_STRUCT(
    (T1)(T2)
  , (::boost::bimaps::relation::structured_pair)
    (T1)
    (T2)
    (boost::bimaps::relation::normal_layout)
  , (
        typename ::boost::fusion::detail::bimap_pair::first_type<T1>::type
      , first
    )
    (
        typename ::boost::fusion::detail::bimap_pair::second_type<T2>::type
      , second
    )
)

BOOST_FUSION_ADAPT_TPL_STRUCT(
    (T1)(T2)
  , (::boost::bimaps::relation::structured_pair)
    (T1)
    (T2)
    (boost::bimaps::relation::mirror_layout)
  , (
        typename ::boost::fusion::detail::bimap_pair::second_type<T2>::type
      , second
    )
    (
        typename ::boost::fusion::detail::bimap_pair::first_type<T1>::type
      , first
    )
)

#endif  // include guard


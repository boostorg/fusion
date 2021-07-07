/*============================================================================
    Copyright (c) 2013-2018 Cromwell D. Enage

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/
#if !defined(BOOST_FUSION_ADAPTED_BOOST_COMPRESSED_PAIR_HPP)
#define BOOST_FUSION_ADAPTED_BOOST_COMPRESSED_PAIR_HPP

#include <boost/fusion/adapted/adt/adapt_adt.hpp>
#include <boost/compressed_pair.hpp>
#include <boost/call_traits.hpp>

BOOST_FUSION_ADAPT_TPL_ADT(
    (T1)(T2)
  , (::boost::compressed_pair)(T1)(T2)
  , (
        typename ::boost::call_traits<T1>::reference
      , typename ::boost::call_traits<T1>::const_reference
      , obj.first()
      , obj.first() = val
    )
    (
        typename ::boost::call_traits<T2>::reference
      , typename ::boost::call_traits<T2>::const_reference
      , obj.second()
      , obj.second() = val
    )
)

#endif  // include guard


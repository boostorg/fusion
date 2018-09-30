/*============================================================================
    Copyright (c) 2013-2018 Cromwell D. Enage

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/
#if !defined(BOOST_FUSION_ADAPTED_BOOST_CONTAINER_PAIR_HPP)
#define BOOST_FUSION_ADAPTED_BOOST_CONTAINER_PAIR_HPP

#include <boost/fusion/adapted/struct/adapt_struct.hpp>
#include <boost/container/detail/pair.hpp>

BOOST_FUSION_ADAPT_TPL_STRUCT(
    (T1)(T2), (::boost::container::dtl::pair)(T1)(T2), (T1, first)(T2, second)
)

#endif  // include guard


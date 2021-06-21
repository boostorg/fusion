/*=============================================================================
    Copyright (c) 2021 Denis Mikhailov

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_STRUCT_ADAPT_PFR_HPP
#define BOOST_FUSION_ADAPTED_STRUCT_ADAPT_PFR_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/adapted/pfr/detail/adapt_base.hpp>
#include <boost/fusion/adapted/pfr/detail/at_impl.hpp>
#include <boost/fusion/adapted/pfr/detail/begin_impl.hpp>
#include <boost/fusion/adapted/pfr/detail/category_of_impl.hpp>
#include <boost/fusion/adapted/pfr/detail/end_impl.hpp>
#include <boost/fusion/adapted/pfr/detail/is_sequence_impl.hpp>
#include <boost/fusion/adapted/pfr/detail/is_view_impl.hpp>
#include <boost/fusion/adapted/pfr/detail/size_impl.hpp>
#include <boost/fusion/adapted/pfr/detail/value_at_impl.hpp>

namespace boost { namespace fusion
{
  struct pfr_tag;
}}

#define BOOST_FUSION_ADAPT_TPL_PFR(TEMPLATE_PARAMS_SEQ,NAME_SEQ)             \
     BOOST_FUSION_ADAPT_PFR_BASE(                                            \
         (1)TEMPLATE_PARAMS_SEQ,                                             \
         (1)NAME_SEQ,                                                        \
         pfr_tag)

#define BOOST_FUSION_ADAPT_PFR(NAME)                                         \
     BOOST_FUSION_ADAPT_PFR_BASE(                                            \
         (0),                                                                \
         (0)(NAME),                                                          \
         pfr_tag)

#endif //BOOST_FUSION_ADAPTED_STRUCT_ADAPT_PFR_HPP

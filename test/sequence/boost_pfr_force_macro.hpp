/*=============================================================================
    Copyright (c) 2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/fusion/adapted/boost_pfr/force.hpp>

struct not_a_sequence {};
BOOST_FUSION_FORCE_PFR_NONREFLECTABLE(not_a_sequence)

struct reflectable {
    explicit reflectable(int first, int second) {}
};
BOOST_FUSION_FORCE_PFR_REFLECTABLE(reflectable)

template<typename T>
struct not_a_sequence_tpl {};
BOOST_FUSION_FORCE_PFR_NONREFLECTABLE_TPL(not_a_sequence_tpl)

template<typename T>
struct reflectable_tpl {
    explicit reflectable_tpl(int first, int second) {}
};
BOOST_FUSION_FORCE_PFR_REFLECTABLE_TPL(reflectable_tpl)



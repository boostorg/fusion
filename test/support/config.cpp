/*=============================================================================
    Copyright (c) 2021-2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/fusion/support/config.hpp>

#include <iostream>

int main() {
    std::cout << "Platform info:" << '\n'
        << "BOOST_FUSION_PFR_ENABLE_IMPLICIT_REFLECTION == " << BOOST_FUSION_PFR_ENABLE_IMPLICIT_REFLECTION << '\n'
        << "BOOST_FUSION_PFR_ENABLED == " << BOOST_FUSION_PFR_ENABLED << '\n'
        << "__cplusplus == " << __cplusplus << '\n'
    ;
}


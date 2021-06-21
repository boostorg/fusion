/*=============================================================================
    Copyright (c) 2021 Denis Mikhailov

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/adapted.hpp>

/// to make sure that the pfr adapter does not generate new compilation errors in old code that depends on inclusion
/// adapted.hpp

int
main()
{
    return boost::report_errors();
}

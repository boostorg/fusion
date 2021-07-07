/*============================================================================
    Copyright (c) 2013-2018 Cromwell D. Enage

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/
#include <boost/fusion/adapted/boost_container_pair.hpp>
#include <boost/container/map.hpp>
#include <string>
#include "adapted_pair.hpp"

int main()
{
    {
        boost::container::map<int, std::string>
        ::movable_value_type p(123, "Hola!!!");
        test::pair_access_and_modify(p);
        BOOST_TEST(boost::fusion::back(p) == "mama mia");
    }

    {
        boost::container::map<short, float>
        ::movable_value_type p(5, 3.3f);
        test::pair_compare(p);
    }

    return boost::report_errors();
}


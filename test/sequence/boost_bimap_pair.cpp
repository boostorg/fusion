/*============================================================================
    Copyright (c) 2013-2018 Cromwell D. Enage

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/
#include <boost/fusion/adapted/boost_bimap_pair.hpp>
#include <string>
#include "adapted_pair.hpp"

int main()
{
    {
        boost::bimaps::relation::structured_pair<
            int
          , std::string
          , boost::bimaps::relation::normal_layout
        > p(123, "Hola!!!");
        test::pair_access_and_modify(p);
        BOOST_TEST(boost::fusion::back(p) == "mama mia");
    }

    {
        boost::bimaps::relation::structured_pair<
            std::string
          , int
          , boost::bimaps::relation::mirror_layout
        > p("Hola!!!", 123);
        test::pair_access_and_modify(p);
        BOOST_TEST(boost::fusion::back(p) == "mama mia");
    }

    {
        boost::bimaps::relation::structured_pair<
            short
          , float
          , boost::bimaps::relation::normal_layout
        > p(5, 3.3f);
        test::pair_compare(p);
    }

    {
        boost::bimaps::relation::structured_pair<
            float
          , short
          , boost::bimaps::relation::mirror_layout
        > p(3.3f, 5);
        test::pair_compare(p);
    }

    return boost::report_errors();
}


/*=============================================================================
    Copyright (c) 2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/adapted/boost_pfr.hpp>
#include <boost/fusion/adapted/boost_pfr/force.hpp>
#include <boost/fusion/support/tag_of.hpp>
#include <type_traits>

struct my_structure {
    int first;
    int second;
};

int
main()
{
    using Tag = boost::fusion::traits::tag_of<my_structure>::type;
    using Tag2 = boost::fusion::traits::tag_of<my_structure& >::type;
    using Tag3 = boost::fusion::traits::tag_of<const my_structure& >::type;
    static_assert(!std::is_same<Tag, boost::fusion::non_fusion_tag>::value, "");
    static_assert(std::is_same<Tag2, boost::fusion::non_fusion_tag>::value, "");
    static_assert(std::is_same<Tag3, boost::fusion::non_fusion_tag>::value, "");
    return boost::report_errors();
} 



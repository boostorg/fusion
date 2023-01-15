/*=============================================================================
    Copyright (c) 2021-2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/adapted/boost_pfr.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/sequence/intrinsic/size.hpp>
#include <boost/fusion/sequence/intrinsic/empty.hpp>
#include <boost/fusion/sequence/intrinsic/front.hpp>
#include <boost/fusion/sequence/intrinsic/back.hpp>
#include <boost/fusion/support/is_view.hpp>
#include <boost/fusion/sequence/io/out.hpp>
#include <boost/fusion/sequence/comparison/equal_to.hpp>
#include <boost/fusion/sequence/comparison/not_equal_to.hpp>
#include <boost/fusion/sequence/comparison/less.hpp>
#include <boost/fusion/sequence/comparison/less_equal.hpp>
#include <boost/fusion/sequence/comparison/greater.hpp>
#include <boost/fusion/sequence/comparison/greater_equal.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/fusion/container/list/list.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>
#include <boost/fusion/include/convert.hpp>
#include <boost/fusion/mpl.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/assert.hpp>
#include <iostream>
#include <string>
#include <cstring>

#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/deque.hpp>
#include <boost/fusion/include/list.hpp>
#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/fusion/include/std_tuple.hpp>

struct SimpleAggregate {
    int first;
    const char* second;
};

template <typename Tag, typename Seq>
void test(Seq const& seq)
{
    const auto v = boost::fusion::convert<Tag>(seq);
    BOOST_TEST((boost::fusion::at_c<0>(v) == 123));
    BOOST_TEST((std::strcmp(boost::fusion::at_c<1>(v), "Hola!!!") == 0));
}

int
main()
{
    SimpleAggregate seq{123, "Hola!!!"};
    test<boost::fusion::vector_tag>(seq);
    test<boost::fusion::deque_tag>(seq);
    test<boost::fusion::cons_tag>(seq);
    test<boost::fusion::boost_tuple_tag>(seq);
    test<boost::fusion::std_tuple_tag>(seq);
    return boost::report_errors();
} 



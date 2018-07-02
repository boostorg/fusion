/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/core/lightweight_test.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>
#include <boost/fusion/sequence/io/out.hpp>
#include <boost/fusion/sequence/comparison/equal_to.hpp>
#include <boost/fusion/algorithm/transformation/replace_if.hpp>

struct gt3
{
    template <typename T>
    bool operator()(T x) const
    {
        return x > 3;
    }
};

struct mutable_gt3 : gt3
{
    template <typename T>
    bool operator()(T x)
    {
        return gt3::operator()(x);
    }
};

int
main()
{
    using namespace boost::fusion;

    std::cout << tuple_open('[');
    std::cout << tuple_close(']');
    std::cout << tuple_delimiter(", ");

/// Testing replace

    {
        char const* s = "Ruby";
        typedef vector<int, short, double, long, char const*, float> vector_type;
        vector_type t1(1, 2, 3.3, 4, s, 5.5f);

        {
            std::cout << replace_if(t1, gt3(), -456) << std::endl;
            BOOST_TEST_EQ(replace_if(t1, gt3(), -456), make_vector(1, 2, -456, -456, s, -456));
        }
    }

    {
        char const* s = "Ruby";
        typedef vector<int, short, double, long, char const*, float> vector_type;
        vector_type t1(1, 2, 3.3, 4, s, 5.5f);

        {
            std::cout << replace_if(t1, mutable_gt3(), -456) << std::endl;
            BOOST_TEST_EQ(replace_if(t1, mutable_gt3(), -456), make_vector(1, 2, -456, -456, s, -456));
        }
    }

    return boost::report_errors();
}


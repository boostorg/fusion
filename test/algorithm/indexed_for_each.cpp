/*=============================================================================
    Copyright (c) 2021 Denis Mikhailov

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/core/lightweight_test.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/fusion/container/list/list.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/adapted/array.hpp>
#include <boost/fusion/sequence/io/out.hpp>
#include <boost/fusion/sequence/comparison/equal_to.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/static_assert.hpp>

struct print
{
    template <typename T, typename I>
    void operator()(T const& v, I) const
    {
        BOOST_STATIC_ASSERT(I::value >= 0);
        std::cout << "[ " << I::value << " : " << v << " ] ";
    }
};

struct increment_control
{
    int& control;

    increment_control(int& control)
        : control(control)
    {}

    template<typename T>
    void operator()(T const& val, int i)
    {
        BOOST_TEST_EQ(i, control);
        (void)val;
        ++ control;
    }
};

struct apply_index_addition
{
    template <typename T>
    void operator()(T& v, int i) const
    {
        v += i;
    }
};

struct mutable_apply_index_addition : apply_index_addition
{
    template <typename T>
    void operator()(T& v, int i)
    {
        return apply_index_addition::operator()(v, i);
    }
};

template<typename V>
struct apply_compile_time_index
{
    template <typename T, typename I>
    void operator()(T, I) const
    {
        using boost::mpl::at;
        typedef typename at<V,I>::type element_type;
        BOOST_STATIC_ASSERT(T::value == element_type::value);
    }
};

int
main()
{
    int control = 0;

    using namespace boost::fusion;
    using boost::mpl::vector_c;
    namespace fusion = boost::fusion;

    {
        typedef vector<int, char, double, char const*> vector_type;
        vector_type v(1, 'x', 3.3, "Ruby");
        for_each(v, print());
        std::cout << std::endl;
    }

    {
        typedef vector<> vector_type;
        vector_type unrolled;
        for_each(unrolled, increment_control(control));
        BOOST_TEST_EQ(control, 0);

        typedef list<> list_type;
        list_type linear;
        for_each(linear, increment_control(control));
        BOOST_TEST_EQ(control, 0);
    }

    {
        control = 0;
        typedef vector<int> vector_type;
        vector_type unrolled ;
        for_each(unrolled, increment_control(control));
        BOOST_TEST_EQ(control, 1);

        control = 0;
        typedef list<int> list_type;
        list_type linear ;
        for_each(linear, increment_control(control));
        BOOST_TEST_EQ(control, 1);
    }

    {
        control = 0;
        typedef vector<int, char, double, char const*> vector_type;
        vector_type unrolled(1, 'x', 3.3, "Ruby");
        for_each(unrolled, increment_control(control));
        BOOST_TEST_EQ(control, 4);

        control = 0;
        typedef list<int, char, double, char const*> list_type;
        list_type linear(1, 'x', 3.3, "Ruby");
        for_each(linear, increment_control(control));
        BOOST_TEST_EQ(control, 4);
    }

    {
        control = 0;
        int array[100] = {};
        for_each(array, increment_control(control));
        BOOST_TEST_EQ(control, 100);
    }

    {
        char const ruby_long[] = "RubyLong";
        typedef vector<int, char, double, char const*> vector_type;
        vector_type v(1, 'x', 3.3, ruby_long);
        for_each(v, apply_index_addition());
        BOOST_TEST_EQ(v, vector_type(1, 'y', 5.3, ruby_long + 3));
        std::cout << v << std::endl;
    }

    {
        char const ruby_long[] = "RubyLong";
        typedef vector<int, char, double, char const*> vector_type;
        vector_type v(1, 'x', 3.3, ruby_long);
        for_each(v, mutable_apply_index_addition());
        BOOST_TEST_EQ(v, vector_type(1, 'y', 5.3, ruby_long + 3));
        std::cout << v << std::endl;
    }

    {
        typedef vector_c<int, 2, 3, 4, 5, 6> mpl_vec;
        fusion::for_each(mpl_vec(), print());
        std::cout << std::endl;
    }

    {
        typedef vector_c<int, 45, 1, 34, 8, 95> mpl_vec;
        fusion::for_each(mpl_vec(), apply_compile_time_index<mpl_vec>());
        std::cout << std::endl;
    }

    return boost::report_errors();
}


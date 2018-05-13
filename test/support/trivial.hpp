/*=============================================================================
    Copyright (c) 2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef TRIVIAL_HPP
#define TRIVIAL_HPP

#include <boost/fusion/support/detail/is_trivially_copyable.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/static_assert.hpp>

#if defined(BOOST_FUSION_DETAIL_VOLATILE_SCALAR_IS_NON_TRIVIALLY_COPYABLE)
#   define BOOST_FUSION_ASSERT_CWG496_SCALAR BOOST_MPL_ASSERT_NOT
#elif defined(BOOST_FUSION_IS_TRIVIALLY_COPYABLE)
#   define BOOST_FUSION_ASSERT_CWG496_SCALAR_I(...) BOOST_STATIC_ASSERT((__VA_ARGS__::value) == BOOST_FUSION_IS_TRIVIALLY_COPYABLE(int volatile))
#   define BOOST_FUSION_ASSERT_CWG496_SCALAR(pred) BOOST_FUSION_ASSERT_CWG496_SCALAR_I pred
#else
#   define BOOST_FUSION_ASSERT_CWG496_SCALAR BOOST_MPL_ASSERT
#endif

#if defined(BOOST_FUSION_IS_TRIVIALLY_COPYABLE)
#   define BOOST_FUSION_ASSERT_CWG496 BOOST_MPL_ASSERT
#   define BOOST_FUSION_ASSERT_CWG2094_I(...) BOOST_STATIC_ASSERT((__VA_ARGS__::value) == BOOST_FUSION_IS_TRIVIALLY_COPYABLE(trivial volatile))
#   define BOOST_FUSION_ASSERT_CWG2094(pred) BOOST_FUSION_ASSERT_CWG2094_I pred
#elif defined(BOOST_FUSION_DETAIL_IS_TRIVIALLY_COPYABLE_CONFORMING)
#   define BOOST_FUSION_ASSERT_CWG496 BOOST_MPL_ASSERT
#   define BOOST_FUSION_ASSERT_CWG2094 BOOST_MPL_ASSERT
#else
#   define BOOST_FUSION_ASSERT_CWG496(pred) struct skip_assertion
#   define BOOST_FUSION_ASSERT_CWG2094(pred) struct skip_assertion
#endif


struct S;
typedef int (S::*member_type);
typedef int (S::*member_function_type)();


struct trivial { };


struct user_provided_copy
{
    user_provided_copy(user_provided_copy const&);
    user_provided_copy& operator=(user_provided_copy const&);
};


#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
struct user_provided_move
{
    user_provided_move(user_provided_move&&);
    user_provided_move& operator=(user_provided_move&&);
};
#endif


struct user_provided_dtor
{
    ~user_provided_dtor();
};

#endif


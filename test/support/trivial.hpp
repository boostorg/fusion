/*=============================================================================
    Copyright (c) 2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef TRIVIAL_HPP
#define TRIVIAL_HPP

#include <boost/fusion/support/detail/is_trivially_copyable.hpp>
#include <boost/mpl/assert.hpp>

#ifndef BOOST_FUSION_DETAIL_VOLATILE_SCALAR_IS_NON_TRIVIALLY_COPYABLE
#   define BOOST_FUSION_ASSERT_WA BOOST_MPL_ASSERT
#else
#   define BOOST_FUSION_ASSERT_WA BOOST_MPL_ASSERT_NOT
#endif

#ifdef BOOST_FUSION_DETAIL_IS_TRIVIALLY_COPYABLE_CONFORMING
#   define BOOST_FUSION_ASSERT_FALLBACK BOOST_MPL_ASSERT
#else
#   define BOOST_FUSION_ASSERT_FALLBACK(cond) BOOST_MPL_ASSERT((boost::mpl::true_))
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
    user_provided_move(user_provided_move const&);
    user_provided_move& operator=(user_provided_move const&);
};
#endif


struct user_provided_dtor
{
    ~user_provided_dtor();
};

#endif


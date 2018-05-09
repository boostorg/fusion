/*=============================================================================
    Copyright (c) 2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/config.hpp>
#include <boost/fusion/support/detail/propagate_trivialness.hpp>
#include <boost/fusion/support/detail/is_trivially_copyable.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/type_traits/is_default_constructible.hpp>
#include "trivial.hpp"

using namespace boost;
using namespace boost::fusion::detail;


BOOST_MPL_ASSERT((is_default_constructible<trivial_base>));
BOOST_MPL_ASSERT((is_default_constructible<non_trivial_base>));

BOOST_FUSION_ASSERT_CWG496((is_trivially_copyable<trivial_base>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<non_trivial_base>));

BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<> >));

BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<int> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<int const> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_base_of<trivial_base, propagate_trivialness<int volatile> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_base_of<trivial_base, propagate_trivialness<int const volatile> >));

BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<int*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<int const*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<int volatile*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<int const volatile*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<int* const> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_base_of<trivial_base, propagate_trivialness<int* volatile> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_base_of<trivial_base, propagate_trivialness<int* const volatile> >));

BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<int&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<int const&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<int volatile&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<int const volatile&> >));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<int&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<int const&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<int volatile&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<int const volatile&&> >));
#endif


BOOST_FUSION_ASSERT_CWG496((is_base_of<trivial_base, propagate_trivialness<trivial> >));
BOOST_FUSION_ASSERT_CWG496((is_base_of<trivial_base, propagate_trivialness<trivial const> >));
BOOST_FUSION_ASSERT_CWG2094((is_base_of<trivial_base, propagate_trivialness<trivial volatile> >));
BOOST_FUSION_ASSERT_CWG2094((is_base_of<trivial_base, propagate_trivialness<trivial const volatile> >));

BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<trivial*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<trivial const*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<trivial volatile*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<trivial const volatile*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<trivial* const> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_base_of<trivial_base, propagate_trivialness<trivial* volatile> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_base_of<trivial_base, propagate_trivialness<trivial* const volatile> >));

BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<trivial&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<trivial const&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<trivial volatile&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<trivial const volatile&> >));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<trivial&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<trivial const&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<trivial volatile&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<trivial const volatile&&> >));
#endif


BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_copy> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_copy const> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_copy volatile> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_copy const volatile> >));

BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_copy*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_copy const*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_copy volatile*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_copy const volatile*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_copy* const> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_base_of<trivial_base, propagate_trivialness<user_provided_copy* volatile> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_base_of<trivial_base, propagate_trivialness<user_provided_copy* const volatile> >));

BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_copy&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_copy const&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_copy volatile&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_copy const volatile&> >));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_copy&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_copy const&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_copy volatile&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_copy const volatile&&> >));
#endif


#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_move> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_move const> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_move volatile> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_move const volatile> >));

BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_move*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_move const*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_move volatile*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_move const volatile*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_move* const> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_base_of<trivial_base, propagate_trivialness<user_provided_move* volatile> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_base_of<trivial_base, propagate_trivialness<user_provided_move* const volatile> >));

BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_move&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_move const&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_move volatile&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_move const volatile&> >));

BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_move&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_move const&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_move volatile&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_move const volatile&&> >));
#endif


BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_dtor> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_dtor const> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_dtor volatile> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_dtor const volatile> >));

BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_dtor*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_dtor const*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_dtor volatile*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_dtor const volatile*> >));
BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<user_provided_dtor* const> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_base_of<trivial_base, propagate_trivialness<user_provided_dtor* volatile> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_base_of<trivial_base, propagate_trivialness<user_provided_dtor* const volatile> >));

BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_dtor&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_dtor const&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_dtor volatile&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_dtor const volatile&> >));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_dtor&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_dtor const&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_dtor volatile&&> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<user_provided_dtor const volatile&&> >));
#endif


BOOST_MPL_ASSERT((is_base_of<trivial_base, propagate_trivialness<int, float, void*> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<int, float&, void*> >));
BOOST_FUSION_ASSERT_CWG496((is_base_of<trivial_base, propagate_trivialness<int, float, trivial> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<int, float, user_provided_copy> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<int, float, user_provided_move> >));
BOOST_MPL_ASSERT((is_base_of<non_trivial_base, propagate_trivialness<int, float, user_provided_dtor> >));


struct S1 : private propagate_trivialness<int, float, void*> { };
BOOST_MPL_ASSERT((is_trivially_copyable<S1>));

struct S2 : private propagate_trivialness<int, float&, void*> { };
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<S2>));

struct S3 : private propagate_trivialness<int, float, trivial> { };
BOOST_FUSION_ASSERT_CWG496((is_trivially_copyable<S3>));

struct S4 : private propagate_trivialness<int, float, user_provided_copy> { };
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<S4>));

struct S5 : private propagate_trivialness<int, float, user_provided_move> { };
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<S5>));

struct S6 : private propagate_trivialness<int, float, user_provided_dtor> { };
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<S6>));

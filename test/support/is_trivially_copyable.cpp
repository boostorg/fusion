/*=============================================================================
    Copyright (c) 2018 Kohei Takahashi
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/config.hpp>

#include <boost/fusion/support/detail/is_trivially_copyable.hpp>
#include <boost/mpl/assert.hpp>
#include "trivial.hpp"

using namespace boost;
using namespace boost::fusion::detail;


BOOST_MPL_ASSERT_NOT((is_trivially_copyable<void>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<void const>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<void volatile>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<void const volatile>));

BOOST_MPL_ASSERT((is_trivially_copyable<int>));
BOOST_MPL_ASSERT((is_trivially_copyable<int const>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int volatile>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int const volatile>));

BOOST_MPL_ASSERT((is_trivially_copyable<int*>));
BOOST_MPL_ASSERT((is_trivially_copyable<int const*>));
BOOST_MPL_ASSERT((is_trivially_copyable<int volatile*>));
BOOST_MPL_ASSERT((is_trivially_copyable<int const volatile*>));
BOOST_MPL_ASSERT((is_trivially_copyable<int* const>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int* volatile>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int* const volatile>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int volatile&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const volatile&>));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int volatile&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const volatile&&>));
#endif

BOOST_MPL_ASSERT((is_trivially_copyable<int[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int const[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int volatile[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int const volatile[]>));

BOOST_MPL_ASSERT((is_trivially_copyable<int[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int const[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int volatile[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int const volatile[3]>));

BOOST_MPL_ASSERT((is_trivially_copyable<int[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int const[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int volatile[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int const volatile[][3][4][5]>));

BOOST_MPL_ASSERT((is_trivially_copyable<int(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int const(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int volatile(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int const volatile(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int(*const)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int(*volatile)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int(*const volatile)[]>));

BOOST_MPL_ASSERT((is_trivially_copyable<int(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int const(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int volatile(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int const volatile(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int(*const)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int(*volatile)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int(*const volatile)[3]>));

BOOST_MPL_ASSERT((is_trivially_copyable<int(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int const(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int volatile(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int const volatile(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<int(*const)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int(*volatile)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<int(*const volatile)[][3][4][5]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int volatile(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const volatile(&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int volatile(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const volatile(&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int volatile(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const volatile(&)[][3][4][5]>));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int volatile(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const volatile(&&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int volatile(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const volatile(&&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int volatile(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<int const volatile(&&)[][3][4][5]>));
#endif

typedef int function_type();
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type volatile>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const volatile>));

BOOST_MPL_ASSERT((is_trivially_copyable<function_type*>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type const*>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type volatile*>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type const volatile*>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type* const>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<function_type* volatile>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<function_type* const volatile>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type volatile&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const volatile&>));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type volatile&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const volatile&&>));
#endif

BOOST_MPL_ASSERT((is_trivially_copyable<function_type*[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type const*[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type volatile*[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type const volatile*[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type* const[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<function_type* volatile[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<function_type* const volatile[]>));

BOOST_MPL_ASSERT((is_trivially_copyable<function_type*[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type const*[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type volatile*[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type const volatile*[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type* const[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<function_type* volatile[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<function_type* const volatile[3]>));

BOOST_MPL_ASSERT((is_trivially_copyable<function_type*[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type const*[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type volatile*[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type const volatile*[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type* const[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<function_type* volatile[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<function_type* const volatile[][3][4][5]>));

BOOST_MPL_ASSERT((is_trivially_copyable<function_type*(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type const*(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type volatile*(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type const volatile*(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type*(*const)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<function_type*(*volatile)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<function_type*(*const volatile)[]>));

BOOST_MPL_ASSERT((is_trivially_copyable<function_type*(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type const*(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type volatile*(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type const volatile*(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type*(*const)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<function_type*(*volatile)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<function_type*(*const volatile)[3]>));

BOOST_MPL_ASSERT((is_trivially_copyable<function_type*(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type const*(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type volatile*(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type const volatile*(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<function_type*(*const)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<function_type*(*volatile)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<function_type*(*const volatile)[][3][4][5]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type*(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const*(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type volatile*(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const volatile*(&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type*(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const*(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type volatile*(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const volatile*(&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type*(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const*(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type volatile*(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const volatile*(&)[][3][4][5]>));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type*(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const*(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type volatile*(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const volatile*(&&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type*(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const*(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type volatile*(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const volatile*(&&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type*(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const*(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type volatile*(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<function_type const volatile*(&&)[][3][4][5]>));
#endif

BOOST_MPL_ASSERT((is_trivially_copyable<member_type>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type const>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_type volatile>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_type const volatile>));

BOOST_MPL_ASSERT((is_trivially_copyable<member_type[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type const[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_type volatile[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_type const volatile[]>));

BOOST_MPL_ASSERT((is_trivially_copyable<member_type[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type const[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_type volatile[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_type const volatile[3]>));

BOOST_MPL_ASSERT((is_trivially_copyable<member_type[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type const[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_type volatile[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_type const volatile[][3][4][5]>));

BOOST_MPL_ASSERT((is_trivially_copyable<member_type(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type const(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type volatile(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type const volatile(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type(*const)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_type(*volatile)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_type(*const volatile)[]>));

BOOST_MPL_ASSERT((is_trivially_copyable<member_type(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type const(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type volatile(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type const volatile(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type(*const)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_type(*volatile)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_type(*const volatile)[3]>));

BOOST_MPL_ASSERT((is_trivially_copyable<member_type(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type const(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type volatile(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type const volatile(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_type(*const)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_type(*volatile)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_type(*const volatile)[][3][4][5]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type const(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type volatile(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type const volatile(&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type const(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type volatile(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type const volatile(&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type const(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type volatile(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type const volatile(&)[][3][4][5]>));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type const(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type volatile(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type const volatile(&&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type const(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type volatile(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type const volatile(&&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type const(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type volatile(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_type const volatile(&&)[][3][4][5]>));
#endif

BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type const>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_function_type volatile>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_function_type const volatile>));

BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type const[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_function_type volatile[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_function_type const volatile[]>));

BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type const[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_function_type volatile[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_function_type const volatile[3]>));

BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type const[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_function_type volatile[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_function_type const volatile[][3][4][5]>));

BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type const(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type volatile(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type const volatile(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type(*const)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_function_type(*volatile)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_function_type(*const volatile)[]>));

BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type const(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type volatile(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type const volatile(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type(*const)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_function_type(*volatile)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_function_type(*const volatile)[3]>));

BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type const(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type volatile(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type const volatile(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<member_function_type(*const)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_function_type(*volatile)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<member_function_type(*const volatile)[][3][4][5]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type const(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type volatile(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type const volatile(&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type const(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type volatile(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type const volatile(&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type const(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type volatile(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type const volatile(&)[][3][4][5]>));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type const(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type volatile(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type const volatile(&&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type const(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type volatile(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type const volatile(&&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type const(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type volatile(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<member_function_type const volatile(&&)[][3][4][5]>));
#endif


BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial>));
BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial const>));
BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial volatile>));
BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial const volatile>));

BOOST_MPL_ASSERT((is_trivially_copyable<trivial*>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial const*>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial volatile*>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial const volatile*>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial* const>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<trivial* volatile>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<trivial* const volatile>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial volatile&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const volatile&>));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial volatile&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const volatile&&>));
#endif

BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial[]>));
BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial const[]>));
BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial volatile[]>));
BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial const volatile[]>));

BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial[3]>));
BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial const[3]>));
BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial volatile[3]>));
BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial const volatile[3]>));

BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial[][3][4][5]>));
BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial const[][3][4][5]>));
BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial volatile[][3][4][5]>));
BOOST_FUSION_ASSERT_FALLBACK((is_trivially_copyable<trivial const volatile[][3][4][5]>));

BOOST_MPL_ASSERT((is_trivially_copyable<trivial(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial const(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial volatile(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial const volatile(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial(*const)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<trivial(*volatile)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<trivial(*const volatile)[]>));

BOOST_MPL_ASSERT((is_trivially_copyable<trivial(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial const(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial volatile(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial const volatile(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial(*const)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<trivial(*volatile)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<trivial(*const volatile)[3]>));

BOOST_MPL_ASSERT((is_trivially_copyable<trivial(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial const(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial volatile(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial const volatile(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<trivial(*const)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<trivial(*volatile)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<trivial(*const volatile)[][3][4][5]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial volatile(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const volatile(&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial volatile(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const volatile(&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial volatile(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const volatile(&)[][3][4][5]>));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial volatile(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const volatile(&&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial volatile(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const volatile(&&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial volatile(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<trivial const volatile(&&)[][3][4][5]>));
#endif


BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy volatile>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const volatile>));

BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy*>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy const*>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy volatile*>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy const volatile*>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy* const>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_copy* volatile>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_copy* const volatile>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy volatile&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const volatile&>));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy volatile&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const volatile&&>));
#endif

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy volatile[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const volatile[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy volatile[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const volatile[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy volatile[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const volatile[][3][4][5]>));

BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy const(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy volatile(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy const volatile(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy(*const)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_copy(*volatile)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_copy(*const volatile)[]>));

BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy const(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy volatile(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy const volatile(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy(*const)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_copy(*volatile)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_copy(*const volatile)[3]>));

BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy const(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy volatile(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy const volatile(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_copy(*const)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_copy(*volatile)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_copy(*const volatile)[][3][4][5]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy volatile(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const volatile(&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy volatile(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const volatile(&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy volatile(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const volatile(&)[][3][4][5]>));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy volatile(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const volatile(&&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy volatile(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const volatile(&&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy volatile(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_copy const volatile(&&)[][3][4][5]>));
#endif


#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move volatile>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const volatile>));

BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move*>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move const*>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move volatile*>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move const volatile*>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move* const>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_move* volatile>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_move* const volatile>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move volatile&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const volatile&>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move volatile&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const volatile&&>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move volatile[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const volatile[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move volatile[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const volatile[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move volatile[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const volatile[][3][4][5]>));

BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move const(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move volatile(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move const volatile(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move(*const)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_move(*volatile)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_move(*const volatile)[]>));

BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move const(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move volatile(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move const volatile(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move(*const)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_move(*volatile)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_move(*const volatile)[3]>));

BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move const(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move volatile(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move const volatile(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_move(*const)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_move(*volatile)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_move(*const volatile)[][3][4][5]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move volatile(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const volatile(&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move volatile(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const volatile(&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move volatile(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const volatile(&)[][3][4][5]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move volatile(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const volatile(&&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move volatile(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const volatile(&&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move volatile(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_move const volatile(&&)[][3][4][5]>));
#endif


BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor volatile>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const volatile>));

BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor*>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor const*>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor volatile*>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor const volatile*>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor* const>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_dtor* volatile>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_dtor* const volatile>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor volatile&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const volatile&>));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor volatile&&>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const volatile&&>));
#endif

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor volatile[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const volatile[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor volatile[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const volatile[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor volatile[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const volatile[][3][4][5]>));

BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor const(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor volatile(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor const volatile(*)[]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor(*const)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_dtor(*volatile)[]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_dtor(*const volatile)[]>));

BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor const(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor volatile(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor const volatile(*)[3]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor(*const)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_dtor(*volatile)[3]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_dtor(*const volatile)[3]>));

BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor const(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor volatile(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor const volatile(*)[][3][4][5]>));
BOOST_MPL_ASSERT((is_trivially_copyable<user_provided_dtor(*const)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_dtor(*volatile)[][3][4][5]>));
BOOST_FUSION_ASSERT_WA((is_trivially_copyable<user_provided_dtor(*const volatile)[][3][4][5]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor volatile(&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const volatile(&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor volatile(&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const volatile(&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor volatile(&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const volatile(&)[][3][4][5]>));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor volatile(&&)[]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const volatile(&&)[]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor volatile(&&)[3]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const volatile(&&)[3]>));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor volatile(&&)[][3][4][5]>));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<user_provided_dtor const volatile(&&)[][3][4][5]>));
#endif

/*=============================================================================
    Copyright (c) 2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <type_traits>
#include <boost/fusion/support/pair.hpp>
#include <boost/mpl/assert.hpp>

using namespace boost::fusion;

struct non_trivially_copyable
{
    non_trivially_copyable(const non_trivially_copyable&);
    non_trivially_copyable operator=(const non_trivially_copyable&);
};

struct pod { };

BOOST_MPL_ASSERT_NOT((std::is_trivially_copyable<void>));
BOOST_MPL_ASSERT((std::is_trivially_copyable<int>));
BOOST_MPL_ASSERT_NOT((std::is_trivially_copyable<non_trivially_copyable>));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pod>));
BOOST_MPL_ASSERT_NOT((std::is_trivially_copyable<int&>));
BOOST_MPL_ASSERT((std::is_trivially_copyable<void*>));



BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<void, int> >));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<int, int> >));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<non_trivially_copyable, int> >));
BOOST_MPL_ASSERT_NOT((std::is_trivially_copyable<pair<int, non_trivially_copyable> >));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<pod, int> >));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<int, pod> >));

BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<void, int&> >));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<int, int&> >));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<non_trivially_copyable, int&> >));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<int, non_trivially_copyable&> >));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<int, pod&> >));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<int, pod&> >));

BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<void, int*> >));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<int, int*> >));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<non_trivially_copyable, int*> >));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<int, non_trivially_copyable*> >));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<int, pod*> >));
BOOST_MPL_ASSERT((std::is_trivially_copyable<pair<int, pod*> >));

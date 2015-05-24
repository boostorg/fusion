/*=============================================================================
    Copyright (c) 2014 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef FUSION_SET_11062014_1726
#define FUSION_SET_11062014_1726

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/container/set/set_fwd.hpp>

///////////////////////////////////////////////////////////////////////////////
// Without variadics, we will use the PP version
///////////////////////////////////////////////////////////////////////////////
#if !defined(BOOST_FUSION_HAS_VARIADIC_SET)
# include <boost/fusion/container/set/detail/cpp03/set.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 interface
///////////////////////////////////////////////////////////////////////////////
#include <boost/fusion/support/detail/access.hpp>
#include <boost/fusion/support/sequence_base.hpp>
#include <boost/fusion/support/category_of.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/fusion/container/set/detail/begin_impl.hpp>
#include <boost/fusion/container/set/detail/end_impl.hpp>
#include <boost/fusion/container/set/detail/value_of_impl.hpp>
#include <boost/fusion/container/set/detail/deref_data_impl.hpp>
#include <boost/fusion/container/set/detail/deref_impl.hpp>
#include <boost/fusion/container/set/detail/key_of_impl.hpp>
#include <boost/fusion/container/set/detail/value_of_data_impl.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/bool.hpp>

namespace boost { namespace fusion
{
    struct fusion_sequence_tag;

    template <>
    struct set<> : sequence_base<set<> >
    {
        struct category : forward_traversal_tag, associative_tag {};

        typedef set_tag fusion_tag;
        typedef fusion_sequence_tag tag; // this gets picked up by MPL
        typedef mpl::false_ is_view;

        typedef vector<> storage_type;

        typedef storage_type::size size;

        BOOST_FUSION_GPU_ENABLED
        set()
            : data() {}

        template <typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        set(Sequence const& rhs)
            : data(rhs) {}

        template <typename T>
        BOOST_FUSION_GPU_ENABLED
        set&
        operator=(T const& rhs)
        {
            data = rhs;
            return *this;
        }

        BOOST_FUSION_GPU_ENABLED
        storage_type& get_data() { return data; }
        BOOST_FUSION_GPU_ENABLED
        storage_type const& get_data() const { return data; }

    private:
        storage_type data;
    };

    template <typename ...T>
    struct set : sequence_base<set<T...> >
    {
        struct category : forward_traversal_tag, associative_tag {};

        typedef set_tag fusion_tag;
        typedef fusion_sequence_tag tag; // this gets picked up by MPL
        typedef mpl::false_ is_view;

        typedef vector<T...> storage_type;

        typedef typename storage_type::size size;

        BOOST_FUSION_GPU_ENABLED
        set()
            : data() {}

        template <typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        set(Sequence const& rhs)
            : data(rhs) {}

        BOOST_FUSION_GPU_ENABLED
        explicit
        set(typename detail::call_param<T>::type ...args)
            : data(args...) {}

        template <typename U>
        BOOST_FUSION_GPU_ENABLED
        set&
        operator=(U const& rhs)
        {
            data = rhs;
            return *this;
        }

        BOOST_FUSION_GPU_ENABLED
        storage_type& get_data() { return data; }
        BOOST_FUSION_GPU_ENABLED
        storage_type const& get_data() const { return data; }

    private:
        storage_type data;
    };

}}

#endif
#endif



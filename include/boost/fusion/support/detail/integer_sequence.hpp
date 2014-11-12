/*=============================================================================
    Copyright (c) 2014 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_FUSION_SUPPORT_DETAIL_INTEGER_SEQUENCE_10232014_1139
#define BOOST_FUSION_SUPPORT_DETAIL_INTEGER_SEQUENCE_10232014_1139

#include <boost/config.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <cstddef>

namespace boost { namespace fusion { namespace detail
{
    template <typename T, T ...Ints>
    struct integer_sequence
    {
        static BOOST_CONSTEXPR std::size_t size() BOOST_NOEXCEPT
        { return sizeof...(Ints); }
    };

    template <typename T, T, typename = integer_sequence<T> >
    struct make_integer_sequence;

    template <typename T, T Head, T ...Tail>
    struct make_integer_sequence<T, Head, integer_sequence<T, Tail...> >
        : boost::mpl::eval_if_c<
              (Head == 0),
              boost::mpl::identity<integer_sequence<T, Tail...> >,
              make_integer_sequence<T, Head - 1, integer_sequence<T, Head - 1, Tail...> >
          > {};
}}}

#endif


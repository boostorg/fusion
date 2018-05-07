/*=============================================================================
    Copyright (c) 2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_FUSION_SUPPORT_DETAIL_IS_TRIVIALLY_COPYABLE
#define BOOST_FUSION_SUPPORT_DETAIL_IS_TRIVIALLY_COPYABLE

#include <boost/fusion/support/config.hpp>

#if BOOST_WORKAROUND(BOOST_GCC, BOOST_TESTED_AT(90000))
    // GCC treats volatile qualified scalar type as non trivially copyable,
    // so to be fail safe, we also treat it as non trivially copyable type.
    // http://wg21.link/cwg2094
    // https://gcc.gnu.org/PR85679
#   define BOOST_FUSION_DETAIL_VOLATILE_SCALAR_IS_NON_TRIVIALLY_COPYABLE
#endif

#ifndef BOOST_NO_CXX11_HDR_TYPE_TRAITS
#   include <type_traits>
#else
#   include <boost/config/workaround.hpp>
#   include <boost/mpl/bool.hpp>
#   include <boost/mpl/if.hpp>
#   include <boost/type_traits/remove_cv.hpp>
#   include <boost/type_traits/remove_all_extents.hpp>
#   include <boost/type_traits/is_scalar.hpp>
#   include <boost/type_traits/is_constructible.hpp>
#   include <boost/type_traits/is_assignable.hpp>
#   include <boost/type_traits/is_copy_constructible.hpp>
#   include <boost/type_traits/is_copy_assignable.hpp>
#   include <boost/type_traits/has_trivial_assign.hpp>
#   include <boost/type_traits/has_trivial_copy.hpp>
#   include <boost/type_traits/has_trivial_destructor.hpp>
#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
#   include <boost/type_traits/has_trivial_move_assign.hpp>
#   include <boost/type_traits/has_trivial_move_constructor.hpp>
#endif
#ifdef BOOST_FUSION_DETAIL_VOLATILE_SCALAR_IS_NON_TRIVIALLY_COPYABLE
#   include <boost/mpl/not.hpp>
#   include <boost/type_traits/is_volatile.hpp>
#endif
#endif // <type_traits>

#ifndef BOOST_NO_CXX11_HDR_TYPE_TRAITS
#   define BOOST_FUSION_DETAIL_IS_TRIVIALLY_COPYABLE_CONFORMING 2
#elif defined(BOOST_SFINAE_EXPR) && !defined(BOOST_NO_CXX11_DECLTYPE) && \
      defined(BOOST_HAS_TRIVIAL_ASSIGN) && defined(BOOST_HAS_TRIVIAL_COPY) && \
      defined(BOOST_HAS_TRIVIAL_MOVE_ASSIGN) && defined(BOOST_HAS_TRIVIAL_MOVE_CONSTRUCTOR) && \
      defined(BOOST_HAS_TRIVIAL_DESTRUCTOR) && defined(BOOST_TT_IS_CONSTRUCTIBLE_CONFORMING)
#   define BOOST_FUSION_DETAIL_IS_TRIVIALLY_COPYABLE_CONFORMING 1
#endif

namespace boost { namespace fusion { namespace detail
{

#ifdef BOOST_NO_CXX11_HDR_TYPE_TRAITS
template <typename T>
struct is_trivially_copyable_class
  : mpl::bool_<
        (has_trivial_copy<T>::value   || !is_copy_constructible<T>::value) &&
        (has_trivial_assign<T>::value || !is_copy_assignable<T>::value) &&
#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
        (has_trivial_move_constructor<T>::value || !is_constructible<T, T&&>::value) &&
        (has_trivial_move_assign<T>::value      || !is_assignable<T, T&&>::value) &&
#endif // rv-ref
        (is_constructible<T, T>::value || is_assignable<T, T>::value) &&
        has_trivial_destructor<T>::value
    > { };

template <typename T>
struct is_trivially_copyable_impl
  : mpl::if_c<is_scalar<T>::value
#ifdef BOOST_FUSION_DETAIL_VOLATILE_SCALAR_IS_NON_TRIVIALLY_COPYABLE
    , mpl::not_<is_volatile<T> >
#else
    , mpl::true_
#endif
    , is_trivially_copyable_class<typename remove_cv<T>::type> >::type { };
#endif // <type_traits>

template <typename T>
struct is_trivially_copyable
#ifndef BOOST_NO_CXX11_HDR_TYPE_TRAITS
  : std::is_trivially_copyable<T>
#else
  : is_trivially_copyable_impl<typename remove_all_extents<T>::type>
#endif // <type_traits>
{ };

}}} // namespace boost::fusion::detail

#endif


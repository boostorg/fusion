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
    //
    // Some version of clang also tweats volatile qualified scalar type as
    // non trivially copyable type, but all of known the versions what
    // behaves as CWG 496 but not CWG 2094 implement builtin.
    // So we don't have to emulate CWG 496 on clang.
#   define BOOST_FUSION_DETAIL_VOLATILE_SCALAR_IS_NON_TRIVIALLY_COPYABLE
#endif

#if BOOST_FUSION_HAS_EXTENSION(is_trivially_copyable) || \
    (50000 <= BOOST_GCC) || (1700 <= BOOST_MSVC)
#   define BOOST_FUSION_IS_TRIVIALLY_COPYABLE __is_trivially_copyable
#endif

#if defined(BOOST_FUSION_IS_TRIVIALLY_COPYABLE)
#   define BOOST_FUSION_DETAIL_IS_TRIVIALLY_COPYABLE_CONFORMING 2
#   include <boost/mpl/bool.hpp>
#elif !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#   define BOOST_FUSION_DETAIL_IS_TRIVIALLY_COPYABLE_CONFORMING 2
#   include <type_traits>
#else
#   include <boost/config/workaround.hpp>
#   include <boost/mpl/bool.hpp>
#   include <boost/mpl/if.hpp>
#   include <boost/type_traits/remove_cv.hpp>
#   include <boost/type_traits/remove_all_extents.hpp>
#   include <boost/type_traits/is_scalar.hpp>
#   include <boost/type_traits/is_class.hpp>
#   include <boost/type_traits/is_union.hpp>
#   include <boost/type_traits/is_constructible.hpp>
#   include <boost/type_traits/is_assignable.hpp>
#   include <boost/type_traits/is_copy_constructible.hpp>
#   include <boost/type_traits/is_copy_assignable.hpp>
#   include <boost/type_traits/has_trivial_assign.hpp>
#   include <boost/type_traits/has_trivial_copy.hpp>
#   include <boost/type_traits/has_trivial_destructor.hpp>
#   include <boost/type_traits/has_trivial_move_assign.hpp>
#   include <boost/type_traits/has_trivial_move_constructor.hpp>
#ifdef BOOST_FUSION_DETAIL_VOLATILE_SCALAR_IS_NON_TRIVIALLY_COPYABLE
#   include <boost/mpl/not.hpp>
#   include <boost/type_traits/is_volatile.hpp>
#endif
#endif // <type_traits>

namespace boost { namespace fusion { namespace detail
{

#ifndef BOOST_FUSION_DETAIL_IS_TRIVIALLY_COPYABLE_CONFORMING
#if defined(BOOST_SFINAE_EXPR) && !defined(BOOST_NO_CXX11_DECLTYPE) && \
    defined(BOOST_IS_UNION) && defined(BOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION) && \
    defined(BOOST_HAS_TRIVIAL_ASSIGN) && defined(BOOST_HAS_TRIVIAL_COPY) && \
    defined(BOOST_HAS_TRIVIAL_MOVE_ASSIGN) && defined(BOOST_HAS_TRIVIAL_MOVE_CONSTRUCTOR) && \
    defined(BOOST_HAS_TRIVIAL_DESTRUCTOR) && defined(BOOST_TT_IS_CONSTRUCTIBLE_CONFORMING)
#   define BOOST_FUSION_DETAIL_IS_TRIVIALLY_COPYABLE_CONFORMING 1
#endif

template <typename T>
struct is_trivially_copyable_class
  : mpl::bool_<
        (has_trivial_copy<T>::value   || !is_copy_constructible<T>::value) &&
        (has_trivial_assign<T>::value || !is_copy_assignable<T>::value) &&
        (has_trivial_move_constructor<T>::value || !is_constructible<T, T>::value) &&
        (has_trivial_move_assign<T>::value      || !is_assignable<T, T>::value) &&
        (is_copy_constructible<T>::value || is_copy_assignable<T>::value ||
         is_constructible<T, T>::value   || is_assignable<T, T>::value) &&
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
    , typename mpl::if_c<is_class<T>::value || is_union<T>::value
      , is_trivially_copyable_class<typename remove_cv<T>::type>
      , mpl::false_
      >::type
    >::type { };
#endif // <type_traits>

template <typename T>
struct is_trivially_copyable
#if defined(BOOST_FUSION_IS_TRIVIALLY_COPYABLE)
  : mpl::bool_<BOOST_FUSION_IS_TRIVIALLY_COPYABLE(T)>
#elif !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
  : std::is_trivially_copyable<T>
#else
  : is_trivially_copyable_impl<typename remove_all_extents<T>::type>
#endif // <type_traits>
{ };

}}} // namespace boost::fusion::detail

#endif


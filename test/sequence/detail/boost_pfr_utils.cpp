/*=============================================================================
    Copyright (c) 2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/fusion/adapted/boost_pfr/tag_of_fallback.hpp>
#include <boost/fusion/support/tag_of.hpp>

#include <type_traits>
#include <boost/type_traits/is_same.hpp>


void test_starts_with() {
    static_assert(!boost::fusion::detail::starts_with("tes", "test"), "");

    static_assert(boost::fusion::detail::starts_with("test", "test"), "");
    static_assert(boost::fusion::detail::starts_with("test", "tes"), "");
    static_assert(boost::fusion::detail::starts_with("test", "te"), "");
    static_assert(boost::fusion::detail::starts_with("test", "t"), "");
    static_assert(boost::fusion::detail::starts_with("test", ""), "");

    static_assert(!boost::fusion::detail::starts_with("test", "tesr"), "");
    static_assert(!boost::fusion::detail::starts_with("test", "tet"), "");
    static_assert(!boost::fusion::detail::starts_with("test", "tq"), "");
    static_assert(!boost::fusion::detail::starts_with("test", "f"), "");

    static_assert(!boost::fusion::detail::starts_with("", "test"), "");
    static_assert(!boost::fusion::detail::starts_with("", "tes"), "");
    static_assert(!boost::fusion::detail::starts_with("", "te"), "");
    static_assert(!boost::fusion::detail::starts_with("", "t"), "");
    static_assert(boost::fusion::detail::starts_with("", ""), "");
}

void test_in_namespace() {
#if BOOST_FUSION_EXPECT_CTTI_TYPE_INDEX_CONSTEXPR_WHEN_UTILS_TEST
    static_assert(boost::fusion::detail::in_namespace< boost::is_same<int,int> >("boost"), "");
    static_assert(boost::fusion::detail::in_namespace< std::is_same<int,int> >("std"), "");
    static_assert(!boost::fusion::detail::in_namespace< int >("std"), "");
#endif
}

void test_constexpr_in_namespace_check_possible() {
    using T = boost::is_same<int,int>;
#if BOOST_FUSION_EXPECT_CTTI_TYPE_INDEX_CONSTEXPR_WHEN_UTILS_TEST
    static_assert(boost::fusion::detail::constexpr_in_namespace_check_possible<T>::value, "");
#elif BOOST_FUSION_EXPECT_CTTI_TYPE_INDEX_NONCONSTEXPR_WHEN_UTILS_TEST
    static_assert(!boost::fusion::detail::constexpr_in_namespace_check_possible<T>::value, "");
#else
#error non properly configured
#endif
}

int main() {
    test_starts_with();
    test_in_namespace();
    test_constexpr_in_namespace_check_possible();
}



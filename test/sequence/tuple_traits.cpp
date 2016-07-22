/*=============================================================================
    Copyright (c) 2016 Lee Clagett

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/tuple/tuple.hpp>
#include <boost/config.hpp>
#include <boost/type_traits/is_constructible.hpp>
#include <boost/type_traits/is_convertible.hpp>

struct test_conversion
{
    test_conversion(int) {}
};

struct test_no_conversion
{
    explicit test_no_conversion(int) {}
};

/*  Some construction differences in fusion::tuple from std::tuple:
      - Construction from elements cannot call an explicit constructor.
      - There is no implicit construction from elements.
      - Construction from std::pair is _enabled_ when tuple is not of size 2.
      - Construction from tuple is _enabled_ when destination tuple is of
        different size.
      - Implicit construction from std::pair can call explicit constructors on
        elements.
      - Implicit construction from tuple can call explicit constructors on
        elements.

    These differences are historical. Matching the behavior of std::tuple
    could break existing code, however, switching to fusion::vector would
    restore the historical behavior. */
int 
main() {
    {
        using namespace boost;
        using namespace boost::fusion;

        BOOST_TEST(!(is_convertible<int, tuple<> >::value));
        BOOST_TEST(!(is_convertible<int&, tuple<> >::value));

        BOOST_TEST(!(is_convertible< int, tuple<int> >::value));
        BOOST_TEST(!(is_convertible< int&, tuple<int> >::value));
        BOOST_TEST(!(is_convertible< vector<int>, tuple<int> >::value));
        BOOST_TEST(!(is_convertible< vector<int>&, tuple<int> >::value));

        BOOST_TEST(!(is_convertible<int, tuple<int, int> >::value));
        BOOST_TEST(!(is_convertible<int&, tuple<int, int> >::value));
    }

// is_constructible has some restrictions ...
#if !(defined(BOOST_NO_CXX11_DECLTYPE) || defined(BOOST_NO_CXX11_TEMPLATES) || \
     defined(BOOST_NO_SFINAE_EXPR))
    {
        using namespace boost;
        using namespace boost::fusion;

        BOOST_TEST((is_constructible< tuple<> >::value));
        BOOST_TEST(!(is_constructible<tuple<>, int>::value));
        BOOST_TEST(!(is_constructible<tuple<>, int&>::value));

        BOOST_TEST((is_constructible< tuple<int> >::value));
        BOOST_TEST((is_constructible<tuple<int>, int>::value));
        BOOST_TEST((is_constructible<tuple<int>, int&>::value));
        BOOST_TEST((is_constructible<tuple<test_conversion>, int>::value));
        BOOST_TEST((is_constructible<tuple<test_conversion>, int&>::value));
        BOOST_TEST(!(is_constructible<tuple<test_no_conversion>, int>::value));
        BOOST_TEST(!(is_constructible<tuple<test_no_conversion>, int&>::value));
        BOOST_TEST(!(is_constructible< tuple<int>, vector<int> >::value));
        BOOST_TEST(!(is_constructible<tuple<int>, vector<int>&>::value));
        BOOST_TEST(!(is_constructible<tuple<int>, int, int>::value));
        BOOST_TEST(!(is_constructible<tuple<int>, int&, int&>::value));

        BOOST_TEST((is_constructible< tuple<int, int> >::value));
        BOOST_TEST((is_constructible<tuple<int, int>, int, int>::value));
        BOOST_TEST((is_constructible<tuple<int, int>, int&, int&>::value));
        BOOST_TEST((
            is_constructible<
                tuple<test_conversion, test_conversion>
              , int
              , int
            >::value
        ));
        BOOST_TEST((
            is_constructible<
                tuple<test_conversion, test_conversion>
              , int&
              , int&
            >::value
        ));
        BOOST_TEST(!(
            is_constructible<
                tuple<test_no_conversion, test_no_conversion>
              , int
              , int
            >::value
        ));
        BOOST_TEST(!(
            is_constructible<
                tuple<test_no_conversion, test_no_conversion>
              , int&
              , int&
            >::value
        ));
#if defined(BOOST_FUSION_HAS_VARIADIC_VECTOR)
        // C++03 fusion::tuple has constructors that can never be used
        BOOST_TEST(!(is_constructible<tuple<int, int>, int>::value));
        BOOST_TEST(!(is_constructible<tuple<int, int>, int&>::value));
#endif
        BOOST_TEST(!(is_constructible<tuple<int, int>, int, int, int>::value));
        BOOST_TEST(!(
            is_constructible<tuple<int, int>, int&, int&, int&>::value
        ));
    }
#endif

    return boost::report_errors();
}

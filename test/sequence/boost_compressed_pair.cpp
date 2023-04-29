/*============================================================================
    Copyright (c) 2013-2018 Cromwell D. Enage

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/
#include <boost/fusion/adapted/boost_compressed_pair.hpp>
#include <string>
#include "adapted_pair.hpp"

namespace test
{
    struct empty_base
    {
    };

    bool operator==(empty_base const&, empty_base const&)
    {
        return true;
    }

    bool operator!=(empty_base const&, empty_base const&)
    {
        return false;
    }
}

int main()
{
    {
        boost::compressed_pair<int, std::string> p(123, "Hola!!!");
        test::pair_access_and_modify(p);
    }

    {
        boost::compressed_pair<short, float> p(5, 3.3f);
        test::pair_compare(p);
    }

    {
        typedef boost::compressed_pair<int, test::empty_base> pair_type;
        BOOST_MPL_ASSERT((boost::mpl::is_sequence<pair_type>));
        BOOST_MPL_ASSERT((
            boost::is_same<int, boost::mpl::front<pair_type>::type>
        ));
        BOOST_MPL_ASSERT((
            boost::is_same<
                test::empty_base
              , boost::mpl::back<pair_type>::type
            >
        ));
        BOOST_MPL_ASSERT((
            boost::is_same<int, boost::mpl::at_c<pair_type,0>::type>
        ));
        BOOST_MPL_ASSERT((
            boost::is_same<
                test::empty_base
              , boost::mpl::at_c<pair_type,1>::type
            >
        ));
        BOOST_MPL_ASSERT((
            boost::mpl::equal_to<
                boost::fusion::result_of::size<pair_type>
              , boost::mpl::int_<2>
            >
        ));
        BOOST_MPL_ASSERT_NOT((boost::fusion::traits::is_view<pair_type>));
        BOOST_MPL_ASSERT_NOT((boost::fusion::result_of::empty<pair_type>));

        pair_type p(123);
        BOOST_TEST(boost::fusion::front(p) == 123);

        boost::fusion::at_c<0>(p) = 6;
        BOOST_TEST(boost::fusion::front(p) == 6);
    }

    {
        typedef boost::compressed_pair<
            test::empty_base
          , std::string
        > pair_type;
        BOOST_MPL_ASSERT((boost::mpl::is_sequence<pair_type>));
        BOOST_MPL_ASSERT((
            boost::is_same<
                test::empty_base
              , boost::mpl::front<pair_type>::type
            >
        ));
        BOOST_MPL_ASSERT((
            boost::is_same<std::string, boost::mpl::back<pair_type>::type>
        ));
        BOOST_MPL_ASSERT((
            boost::is_same<
                test::empty_base
              , boost::mpl::at_c<pair_type,0>::type
            >
        ));
        BOOST_MPL_ASSERT((
            boost::is_same<std::string, boost::mpl::at_c<pair_type,1>::type>
        ));
        BOOST_MPL_ASSERT((
            boost::mpl::equal_to<
                boost::fusion::result_of::size<pair_type>
              , boost::mpl::int_<2>
            >
        ));
        BOOST_MPL_ASSERT_NOT((boost::fusion::traits::is_view<pair_type>));
        BOOST_MPL_ASSERT_NOT((boost::fusion::result_of::empty<pair_type>));

        pair_type p("Hola!!!");
        BOOST_TEST(
            p == boost::fusion::make_vector(test::empty_base(), "Hola!!!")
        );

        boost::fusion::at_c<1>(p) = "mama mia";
        BOOST_TEST(
            p == boost::fusion::make_vector(test::empty_base(), "mama mia")
        );
    }

    {
        typedef boost::compressed_pair<short, short> pair_type;
        BOOST_MPL_ASSERT((boost::mpl::is_sequence<pair_type>));
        BOOST_MPL_ASSERT((
            boost::is_same<short, boost::mpl::front<pair_type>::type>
        ));
        BOOST_MPL_ASSERT((
            boost::is_same<short, boost::mpl::back<pair_type>::type>
        ));
        BOOST_MPL_ASSERT((
            boost::is_same<short, boost::mpl::at_c<pair_type,0>::type>
        ));
        BOOST_MPL_ASSERT((
            boost::is_same<short, boost::mpl::at_c<pair_type,1>::type>
        ));
        BOOST_MPL_ASSERT((
            boost::mpl::equal_to<
                boost::fusion::result_of::size<pair_type>
              , boost::mpl::int_<2>
            >
        ));
        BOOST_MPL_ASSERT_NOT((boost::fusion::traits::is_view<pair_type>));
        BOOST_MPL_ASSERT_NOT((boost::fusion::result_of::empty<pair_type>));

        pair_type p(456);
        BOOST_TEST(p == boost::fusion::make_vector(456, 456));

        boost::fusion::vector<short, short> v(p);
        BOOST_TEST(v == p);
        v = p;
        BOOST_TEST(v == p);

        boost::fusion::list<short, short> l(p);
        BOOST_TEST(l == p);
        l = p;
        BOOST_TEST(l == p);

        boost::fusion::at_c<0>(p) = 7;
        boost::fusion::at_c<1>(p) = 8;
        BOOST_TEST(p == boost::fusion::make_vector(7, 8));
        BOOST_TEST(boost::fusion::front(p) == 7);
#if 0
        BOOST_TEST(boost::fusion::back(p) == 8);
#endif
    }

    return boost::report_errors();
}


/*=============================================================================
    Copyright (c) 2021-2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/adapted/boost_pfr_explicit.hpp>
#include <boost/fusion/support/tag_of.hpp>
#include <boost/type_traits/is_same.hpp>

struct not_a_sequence {};
BOOST_FUSION_FORCE_PFR_NONREFLECTABLE(not_a_sequence)

struct reflectable {
    explicit reflectable(int first, int second) {}
};
BOOST_FUSION_FORCE_PFR_REFLECTABLE(reflectable)

template<typename T>
struct not_a_sequence_tpl {};
BOOST_FUSION_FORCE_PFR_NONREFLECTABLE_TPL(not_a_sequence_tpl)

template<typename T>
struct reflectable_tpl {
    explicit reflectable_tpl(int first, int second) {}
};
BOOST_FUSION_FORCE_PFR_REFLECTABLE_TPL(reflectable_tpl)


int
main()
{
    {
        using Tag = boost::fusion::traits::tag_of<not_a_sequence>::type;
        using Tag2 = boost::fusion::traits::tag_of<reflectable>::type;
        using Tag3 = boost::fusion::traits::tag_of<not_a_sequence_tpl<int>>::type;
        using Tag4 = boost::fusion::traits::tag_of<reflectable_tpl<int>>::type;
        BOOST_STATIC_ASSERT((boost::is_same<Tag, boost::fusion::non_fusion_tag>::value));
        BOOST_STATIC_ASSERT((!boost::is_same<Tag2, boost::fusion::non_fusion_tag>::value));
        BOOST_STATIC_ASSERT((boost::is_same<Tag3, boost::fusion::non_fusion_tag>::value));
        BOOST_STATIC_ASSERT((!boost::is_same<Tag4, boost::fusion::non_fusion_tag>::value));
    }
    {
        using Tag = boost::fusion::traits::tag_of<const not_a_sequence>::type;
        using Tag2 = boost::fusion::traits::tag_of<const reflectable>::type;
        using Tag3 = boost::fusion::traits::tag_of<const not_a_sequence_tpl<int>>::type;
        using Tag4 = boost::fusion::traits::tag_of<const reflectable_tpl<int>>::type;
        BOOST_STATIC_ASSERT((boost::is_same<Tag, boost::fusion::non_fusion_tag>::value));
        BOOST_STATIC_ASSERT((!boost::is_same<Tag2, boost::fusion::non_fusion_tag>::value));
        BOOST_STATIC_ASSERT((boost::is_same<Tag3, boost::fusion::non_fusion_tag>::value));
        BOOST_STATIC_ASSERT((!boost::is_same<Tag4, boost::fusion::non_fusion_tag>::value));
    }
    return boost::report_errors();
} 



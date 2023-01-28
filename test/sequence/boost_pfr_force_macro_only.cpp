/*=============================================================================
    Copyright (c) 2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/support/tag_of.hpp>
#include <boost/type_traits/is_same.hpp>

#include "boost_pfr_force_macro.hpp"

int
main()
{
    {
        typedef boost::fusion::traits::tag_of<not_a_sequence>::type Tag;
        typedef boost::fusion::traits::tag_of<reflectable>::type Tag2;
        typedef boost::fusion::traits::tag_of<not_a_sequence_tpl<int> >::type Tag3;
        typedef boost::fusion::traits::tag_of<reflectable_tpl<int> >::type Tag4;
        BOOST_STATIC_ASSERT((boost::is_same<Tag, boost::fusion::non_fusion_tag>::value));
        BOOST_STATIC_ASSERT((boost::is_same<Tag2, boost::fusion::non_fusion_tag>::value));
        BOOST_STATIC_ASSERT((boost::is_same<Tag3, boost::fusion::non_fusion_tag>::value));
        BOOST_STATIC_ASSERT((boost::is_same<Tag4, boost::fusion::non_fusion_tag>::value));
    }
    {
        typedef boost::fusion::traits::tag_of<const not_a_sequence>::type Tag;
        typedef boost::fusion::traits::tag_of<const reflectable>::type Tag2;
        typedef boost::fusion::traits::tag_of<const not_a_sequence_tpl<int> >::type Tag3;
        typedef boost::fusion::traits::tag_of<const reflectable_tpl<int> >::type Tag4;
        BOOST_STATIC_ASSERT((boost::is_same<Tag, boost::fusion::non_fusion_tag>::value));
        BOOST_STATIC_ASSERT((boost::is_same<Tag2, boost::fusion::non_fusion_tag>::value));
        BOOST_STATIC_ASSERT((boost::is_same<Tag3, boost::fusion::non_fusion_tag>::value));
        BOOST_STATIC_ASSERT((boost::is_same<Tag4, boost::fusion::non_fusion_tag>::value));
    }
    return boost::report_errors();
} 



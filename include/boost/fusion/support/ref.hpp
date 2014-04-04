/*//////////////////////////////////////////////////////////////////////////////
    Copyright (c) 2013 Jamboree

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//////////////////////////////////////////////////////////////////////////////*/
#ifndef BOOST_FUSION_SUPPORT_REF_HPP_INCLUDED
#define BOOST_FUSION_SUPPORT_REF_HPP_INCLUDED


#include <boost/ref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/fusion/support/tag_of_fwd.hpp>


namespace boost { namespace fusion
{
    struct reference_wrapper_tag;
}}

namespace boost { namespace fusion { namespace traits
{
    template<typename T>
    struct tag_of<reference_wrapper<T> >
    {
        typedef reference_wrapper_tag type;
    };
}}}

namespace boost { namespace fusion { namespace extension
{
    template<typename Tag>
    struct category_of_impl;
    
    template<typename Tag>
    struct begin_impl;

    template<typename Tag>
    struct end_impl;

    template<typename Tag>
    struct at_impl;

    template<typename Tag>
    struct value_at_impl;

    template<typename Tag>
    struct size_impl;

    template<typename Tag>
    struct at_key_impl;

    template<typename Tag>
    struct value_at_key_impl;

    template<typename Tag>
    struct has_key_impl;

    template<typename Tag>
    struct is_sequence_impl;

    template<typename Tag>
    struct is_view_impl;

    template<typename Tag>
    struct is_segmented_impl;
    
    template<>
    struct category_of_impl<reference_wrapper_tag>
    {
        template<typename Sequence>
        struct apply
          : category_of_impl<typename traits::tag_of<typename Sequence::type>::type>::
                template apply<typename Sequence::type>
        {};
    };
    
    template<>
    struct begin_impl<reference_wrapper_tag>
    {
        template<typename Sequence>
        struct apply
          : begin_impl<typename traits::tag_of<typename Sequence::type>::type>::
                template apply<typename Sequence::type>
        {};
    };
    
    template<>
    struct end_impl<reference_wrapper_tag>
    {
        template<typename Sequence>
        struct apply
          : end_impl<typename traits::tag_of<typename Sequence::type>::type>::
                template apply<typename Sequence::type>
        {};
    };

    template<>
    struct at_impl<reference_wrapper_tag>
    {
        template<typename Sequence, typename N>
        struct apply
          : at_impl<typename traits::tag_of<typename Sequence::type>::type>::
                template apply<typename Sequence::type, N>
        {};
    };

    template<>
    struct value_at_impl<reference_wrapper_tag>
    {
        template<typename Sequence, typename N>
        struct apply
          : value_at_impl<typename traits::tag_of<typename Sequence::type>::type>::
                template apply<typename Sequence::type, N>
        {};
    };

    template<>
    struct size_impl<reference_wrapper_tag>
    {
        template<typename Sequence>
        struct apply
          : size_impl<typename traits::tag_of<typename Sequence::type>::type>::
                template apply<typename Sequence::type>
        {};
    };

    template<>
    struct value_at_key_impl<reference_wrapper_tag>
    {
        template<typename Sequence, typename Key>
        struct apply
          : value_at_key_impl<typename traits::tag_of<typename Sequence::type>::type>::
                template apply<typename Sequence::type, Key>
        {};
    };

    template<>
    struct at_key_impl<reference_wrapper_tag>
    {
        template<typename Sequence, typename Key>
        struct apply
          : at_key_impl<typename traits::tag_of<typename Sequence::type>::type>::
                template apply<typename Sequence::type, Key>
        {};
    };

    template<>
    struct has_key_impl<reference_wrapper_tag>
    {
        template<typename Sequence, typename Key>
        struct apply
          : has_key_impl<typename traits::tag_of<typename Sequence::type>::type>::
                template apply<typename Sequence::type, Key>
        {};
    };

    template<>
    struct is_sequence_impl<reference_wrapper_tag>
    {
        template<typename T>
        struct apply
          : is_sequence_impl<typename traits::tag_of<typename T::type>::type>::
                template apply<typename T::type>
        {};
    };

    template<>
    struct is_view_impl<reference_wrapper_tag>
      : is_sequence_impl<reference_wrapper_tag>
    {};
    
    template<>
    struct is_segmented_impl<reference_wrapper_tag>
    {
        template<typename T>
        struct apply
          : is_segmented_impl<typename traits::tag_of<typename T::type>::type>::
                template apply<typename T::type>
        {};
    };
}}}


#endif


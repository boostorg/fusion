/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_PFR_FIELDS_VIEW_ITERATOR_HPP_INCLUDED)
#define BOOST_FUSION_PFR_FIELDS_VIEW_ITERATOR_HPP_INCLUDED

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/support/iterator_base.hpp>
#include <boost/fusion/view/pfr_fields_view/detail/advance_impl.hpp>
#include <boost/fusion/view/pfr_fields_view/detail/deref_data_impl.hpp>
#include <boost/fusion/view/pfr_fields_view/detail/deref_impl.hpp>
#include <boost/fusion/view/pfr_fields_view/detail/distance_impl.hpp>
#include <boost/fusion/view/pfr_fields_view/detail/next_impl.hpp>
#include <boost/fusion/view/pfr_fields_view/detail/prior_impl.hpp>
#include <boost/fusion/view/pfr_fields_view/detail/value_of_impl.hpp>
#include <boost/fusion/view/pfr_fields_view/detail/value_of_data_impl.hpp>
#include <boost/pfr/tuple_size.hpp>

namespace boost { namespace fusion
{
    struct pfr_fields_view_iterator_tag;
    struct random_access_traversal_tag;

    template<typename Aggregate, typename Pos>
    struct pfr_fields_view_iterator
        : iterator_base< pfr_fields_view_iterator<Aggregate, Pos> >
    {
        static_assert(Pos::value >=0 && Pos::value <= boost::pfr::tuple_size<Aggregate>::value, "out of range");
        using fusion_tag = pfr_fields_view_iterator_tag;
        using category = random_access_traversal_tag;

        using aggregate_type = Aggregate;
        using index = Pos;

        constexpr BOOST_FUSION_GPU_ENABLED
        explicit pfr_fields_view_iterator(Aggregate& in_agg)
            : agg(in_agg)
        {}

        Aggregate& agg;
    };
}}

#ifdef BOOST_FUSION_WORKAROUND_FOR_LWG_2408
namespace std
{
    template<typename Aggregate, typename Pos>
    struct iterator_traits< ::boost::fusion::pfr_fields_view_iterator<Aggregate, Pos> >
    { };
}
#endif

#endif
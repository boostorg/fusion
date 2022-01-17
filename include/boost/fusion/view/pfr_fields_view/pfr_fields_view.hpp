/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_PFR_FIELDS_VIEW_HPP_INCLUDED)
#define BOOST_FUSION_PFR_FIELDS_VIEW_HPP_INCLUDED

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/view/pfr_fields_view/pfr_fields_view_iterator.hpp>
#include <boost/fusion/view/pfr_fields_view/detail/at_impl.hpp>
#include <boost/fusion/view/pfr_fields_view/detail/begin_impl.hpp>
#include <boost/fusion/view/pfr_fields_view/detail/end_impl.hpp>
#include <boost/fusion/view/pfr_fields_view/detail/value_at_impl.hpp>
#include <boost/fusion/support/sequence_base.hpp>
#include <boost/pfr/tuple_size.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/int.hpp>

namespace boost { namespace fusion
{
    struct pfr_fields_view_tag;
    struct random_access_traversal_tag;
    struct fusion_sequence_tag;

    template<typename Aggregate>
    struct pfr_fields_view : sequence_base<pfr_fields_view<Aggregate>>
    {
        using fusion_tag = pfr_fields_view_tag;
        using tag = fusion_sequence_tag; // this gets picked up by MPL
        using category = random_access_traversal_tag;
        using is_view = mpl::true_;

        using aggregate_type = Aggregate;
        using size = mpl::int_<boost::pfr::tuple_size<Aggregate>::value>;

        constexpr BOOST_FUSION_GPU_ENABLED
        explicit pfr_fields_view(Aggregate& in_agg)
            : agg(in_agg)
        {}

        constexpr BOOST_FUSION_GPU_ENABLED
        pfr_fields_view(pfr_fields_view const& rhs)
            : agg(rhs.agg)
        {}

        Aggregate& agg;
    };
}}

#endif
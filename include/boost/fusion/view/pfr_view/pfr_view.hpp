/*=============================================================================
    Copyright (c) 2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(BOOST_FUSION_PFR_VIEW_HPP_INCLUDED)
#define BOOST_FUSION_PFR_VIEW_HPP_INCLUDED

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/support/is_sequence.hpp>
#include <boost/mp11/utility.hpp>
#include <boost/fusion/view/pfr_fields_view.hpp>
#include <boost/fusion/view/identity_view.hpp>

namespace boost { namespace fusion {
    template<typename T> struct pfr_view 
        : mp11::mp_eval_if<
            traits::is_sequence<T>
          , mp11::mp_eval_if_not<
                traits::is_sequence<T>
              , void
              , identity_view, T
            >
          , pfr_fields_view, T
        >
    {
        using base_type
        = mp11::mp_eval_if<
            traits::is_sequence<T>
          , mp11::mp_eval_if_not<
                traits::is_sequence<T>
              , void
              , identity_view, T
            >
          , pfr_fields_view, T
        >;
        using base_type::base_type;
    };
}}
#endif

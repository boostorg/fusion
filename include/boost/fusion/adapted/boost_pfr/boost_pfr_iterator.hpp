/*=============================================================================
    Copyright (c) 2021-2022 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_BOOST_PFR_ITERATOR_HPP
#define BOOST_FUSION_ADAPTED_BOOST_PFR_ITERATOR_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/iterator/iterator_facade.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/pfr/core.hpp>
#include <utility>
#include <type_traits> // for std::add_const_t, std::remove_const_t, std::is_same

namespace boost { namespace fusion
{
    struct random_access_traversal_tag;

    template <typename Reflectable, int Index>
    struct pfr_iterator_identity;

    template <typename Reflectable, int Index>
    struct boost_pfr_iterator
            : iterator_facade<
                      boost_pfr_iterator<Reflectable, Index>
                    , random_access_traversal_tag>
    {
        static_assert(Index >=0 && Index <= boost::pfr::tuple_size_v<Reflectable>, "out of range");
        using reflectable_type = Reflectable;
        using identity = pfr_iterator_identity<std::add_const_t<Reflectable>, Index>;

        static constexpr auto index = Index;

        constexpr BOOST_FUSION_GPU_ENABLED
        explicit boost_pfr_iterator(Reflectable& reflectable) noexcept
        : reflectable(reflectable) {}

        Reflectable& reflectable;

        template <typename Iterator>
        struct value_of
            : boost::pfr::tuple_element<Iterator::index,
                    std::remove_const_t<typename Iterator::reflectable_type>> {};

        template <typename Iterator>
        struct deref
        {
            using type = decltype(boost::pfr::get<Index>(
                std::declval<Iterator const&>().reflectable));
            static_assert(std::is_reference<type>::value, "internal error");

            constexpr BOOST_FUSION_GPU_ENABLED
            static decltype(auto)
            call(Iterator const& iter) noexcept
            {
                return boost::pfr::get<Index>(iter.reflectable);
            }
        };

        template <typename Iterator, typename N>
        struct advance
        {
            static constexpr auto index = Iterator::index;
            using reflectable_type = typename Iterator::reflectable_type;
            using type = boost_pfr_iterator<reflectable_type, index+N::value>;

            constexpr BOOST_FUSION_GPU_ENABLED
            static auto
            call(Iterator const& i) noexcept
            {
                return type(i.reflectable);
            }
        };

        template <typename Iterator>
        struct next : advance<Iterator, mpl::int_<1>> {};

        template <typename Iterator>
        struct prior : advance<Iterator, mpl::int_<-1>> {};

        template <typename First, typename Last>
        struct equal_to : mpl::bool_<std::is_same<typename First::identity,
                                                  typename Last::identity
                                                  >
                                                ::value>
        {
        };

        template <typename First, typename Last>
        struct distance
        {
            using type = mpl::int_<Last::index-First::index>;

            constexpr BOOST_FUSION_GPU_ENABLED
            static auto
            call(First const&, Last const&) noexcept
            {
                return type();
            }
        };
    };
}}

#endif //BOOST_FUSION_ADAPTED_BOOST_PFR_ITERATOR_HPP


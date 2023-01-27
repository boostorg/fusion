/*=============================================================================
    Copyright (c) 2021-2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_ADAPTED_BOOST_PFR_TAG_OF_FALLBACK_HPP
#define BOOST_FUSION_ADAPTED_BOOST_PFR_TAG_OF_FALLBACK_HPP

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/support/tag_of_fwd.hpp>
#include <boost/type_index/ctti_type_index.hpp>
#include <boost/type_traits/is_complete.hpp>
#include <boost/pfr/traits.hpp>
#include <type_traits>

namespace boost { namespace pfr {
  struct boost_fusion_tag;
}} // namespace boost::pfr

namespace boost { namespace fusion
{
    struct boost_pfr_tag;
    struct non_fusion_tag;
    struct fusion_sequence_tag;

    namespace detail
    {
        // Helper function that returns true if `name` starts with `substr`
        template <std::size_t N>
        constexpr bool starts_with(const char* name, const char (&substr)[N]) noexcept {
            static_assert(N > 0, "non a zero-terminated string passed");
            for (std::size_t i = 0; i<N-1; ++i) {
                if (name[i] != substr[i]) {
                    return false;
                }
            }
            return true;
        }

        // Function that returns true if `T` declared in namespace `ns`
        // got from here: https://www.boost.org/doc/libs/1_81_0/doc/html/boost_typeindex/examples.html#boost_typeindex.examples.c_14_checking_namespace_at_compi
        // TODO: test for it
        template <class T, std::size_t N>
        constexpr bool in_namespace(const char (&ns)[N]) noexcept {
            const char* name = boost::typeindex::ctti_type_index::type_id<T>().raw_name();

            // Some compilers add `class ` or `struct ` before the namespace, so we need to skip those words first
            if (detail::starts_with(name, "class ")) {
                name += sizeof("class ") - 1;
            } else if (detail::starts_with(name, "struct ")) {
                name += sizeof("struct ") - 1;
            }

            return detail::starts_with(name, ns) && detail::starts_with(name + N - 1, "::");
        }

        template<typename T>
        struct constexpr_in_namespace_check_possible {
            template <bool = detail::in_namespace<T>("") >
            static std::true_type test(long) noexcept;

            static std::false_type test(...) noexcept;

            static constexpr bool value = decltype(test(0)){};
        };

        template<typename T>
        constexpr bool is_implicitly_reflectable_via_pfr() noexcept {
            static_assert(detail::constexpr_in_namespace_check_possible<T>::value
                        , "Unfortunately, Boost PFR with implicit reflection won't work in your compiler due to constexpr limitations. "
                          "Please, try to use another compiler or disable implicit reflection by '-DBOOST_FUSION_PFR_ENABLE_IMPLICIT_REFLECTION=0'");
            static_assert(boost::is_complete<T>::value
                        , "Boost Fusion doesn't work with incomplete types if Boost PFR is used as implicit fallback. "
                          "Please, don't pass incomplete types into Boost Fusion or just disable implicit reflection by '-DBOOST_FUSION_PFR_ENABLE_IMPLICIT_REFLECTION=0'");
            const auto possible_pfr = boost::pfr::is_implicitly_reflectable<
                T, boost::pfr::boost_fusion_tag>::value;
            const auto value = !std::is_array<T>::value
                          // FIXME do we need this?
                          // && !std::is_reference<T>::value
                          && !detail::in_namespace<T>("boost::fusion")
                          && !detail::in_namespace<T>("boost::mpl")
                          && !detail::in_namespace<T>("mpl_")
                          && possible_pfr;
            return value;
        }

        template <typename T>
        struct tag_of_fallback<T, std::enable_if_t<detail::is_implicitly_reflectable_via_pfr<T>()>>
        {
            using type = boost_pfr_tag;
        };
    }
}}

#endif //BOOST_FUSION_ADAPTED_BOOST_PFR_TAG_OF_FALLBACK_HPP


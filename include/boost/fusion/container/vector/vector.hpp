/*=============================================================================
    Copyright (c) 2014 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef FUSION_VECTOR_11052014_1625
#define FUSION_VECTOR_11052014_1625

#include <boost/config.hpp>
#include <boost/fusion/support/config.hpp>
#include <boost/fusion/container/vector/detail/config.hpp>
#include <boost/fusion/container/vector/vector_fwd.hpp>

///////////////////////////////////////////////////////////////////////////////
// Without variadics, we will use the PP version
///////////////////////////////////////////////////////////////////////////////
#if !defined(BOOST_FUSION_HAS_VARIADIC_VECTOR)
# include <boost/fusion/container/vector/detail/cpp03/vector.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 interface
///////////////////////////////////////////////////////////////////////////////
#include <boost/fusion/support/sequence_base.hpp>
#include <boost/fusion/support/is_sequence.hpp>
#include <boost/fusion/support/detail/integer_sequence.hpp>
#include <boost/fusion/support/detail/is_constructible.hpp>
#include <boost/fusion/container/vector/detail/at_impl.hpp>
#include <boost/fusion/container/vector/detail/value_at_impl.hpp>
#include <boost/fusion/container/vector/detail/begin_impl.hpp>
#include <boost/fusion/container/vector/detail/end_impl.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/sequence/intrinsic/size.hpp>
#include <boost/fusion/sequence/intrinsic/begin.hpp>
#include <boost/fusion/iterator/advance.hpp>
#include <boost/fusion/iterator/deref.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/or.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/type_traits/is_rvalue_reference.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <cstddef>
#include <utility>

namespace boost { namespace fusion
{
    struct vector_tag;
    struct random_access_traversal_tag;

    namespace vector_detail
    {
        // mandatory_at_c allows to access Nth element even if ForwardSequence
        // since fusion::at_c requires RandomAccessSequence.
        namespace result_of
        {
            template <typename Sequence, int N>
            struct mandatory_at_c
                : fusion::result_of::deref<
                      typename fusion::result_of::advance_c<
                          typename fusion::result_of::begin<Sequence>::type
                        , N
                      >::type
                  >
            {};
        }

        template <int N, typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        inline typename result_of::mandatory_at_c<Sequence, N>::type
        mandatory_at_c(Sequence& seq)
        {
            return *advance_c<N>(begin(seq));
        }

        namespace traits
        {
            template <typename T>
            struct remove_rvalue_reference
                : mpl::if_<
                      is_rvalue_reference<T>
                    , typename remove_reference<T>::type
                    , T
                  >
            {};

            template <typename T>
            struct pure
                : remove_cv<typename remove_reference<T>::type>
            {};
        }

        namespace result_of
        {
            template <typename Sequence, int N
                    , typename S = typename remove_reference<Sequence>::type
                    , typename T = typename result_of::mandatory_at_c<S, N>::type>
            struct forward_at_c
                : traits::remove_rvalue_reference<T>
            {};
        }

        template <int N, typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        inline typename result_of::forward_at_c<Sequence, N>::type
        forward_at_c(Sequence&& seq)
        {
            typedef typename
                result_of::forward_at_c<Sequence, N>::type
            result;
            return std::forward<result>(mandatory_at_c<N>(seq));
        }

        template <typename Base>
        BOOST_FUSION_GPU_ENABLED
        inline Base const&
        as_base(Base const& base) BOOST_NOEXCEPT
        {
            return base;
        }

        template <typename Base>
        BOOST_FUSION_GPU_ENABLED
        inline Base&&
        as_base(Base&& base) BOOST_NOEXCEPT
        {
            return std::forward<Base>(base);
        }

        template <typename Sequence>
        struct make_indices_from_seq
            : detail::make_integer_sequence<
                  std::size_t
                , fusion::result_of::size<typename remove_reference<Sequence>::type>::value
              >
        {};

        // Object proxy since preserve object order
        template <std::size_t, typename T>
        struct store
        {
            BOOST_FUSION_GPU_ENABLED
            store()
                : elem()
            {}

            BOOST_FUSION_GPU_ENABLED
            store(store const& rhs)
                : elem(rhs.get())
            {}

            BOOST_FUSION_GPU_ENABLED
            store&
            operator=(store const& rhs)
            {
                elem = rhs.get();
                return *this;
            }

            BOOST_FUSION_GPU_ENABLED
            store(store&& rhs)
                : elem(std::forward<T>(rhs.get()))
            {}

            BOOST_FUSION_GPU_ENABLED
            store&
            operator=(store&& rhs)
            {
                elem = std::forward<T>(rhs.get());
                return *this;
            }

            template <typename U>
            BOOST_FUSION_GPU_ENABLED
            store(U&& rhs
                , typename enable_if<
                      mpl::or_<
                          detail::is_constructible<T, typename traits::remove_rvalue_reference<U>::type>
                        , is_convertible<typename traits::remove_rvalue_reference<U>::type, T>
                      >
                  >::type* = 0)
                : elem(std::forward<U>(rhs))
            {}

            template <typename U>
            BOOST_FUSION_GPU_ENABLED
            store&
            operator=(U&& rhs)
            {
                elem = std::forward<U>(rhs);
                return *this;
            }

            BOOST_FUSION_GPU_ENABLED T      & get()       { return elem; }
            BOOST_FUSION_GPU_ENABLED T const& get() const { return elem; }

            T elem;
        };

        template <std::size_t I, typename... T>
        struct data;

        template <std::size_t I>
        struct data<I>
        {
            typedef mpl::int_<(int)I> size;

            BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
            void
            assign() BOOST_NOEXCEPT
            {}
        };

        template <std::size_t I, typename T, typename... Tail>
        struct data<I, T, Tail...>
            : store<I, T>, data<I + 1, Tail...>
        {
            typedef store<I, T>             elem;
            typedef data<I + 1, Tail...>    base;

            BOOST_FUSION_GPU_ENABLED
            data()
            {}

            BOOST_FUSION_GPU_ENABLED
            data(data const& rhs)
                : elem(static_cast<elem const&>(rhs))
                , base(static_cast<base const&>(rhs))
            {}

            BOOST_FUSION_GPU_ENABLED
            data(data&& rhs)
                : elem(std::forward<elem>(rhs))
                , base(std::forward<base>(rhs))
            {}

            template <typename Sequence, std::size_t ...N>
            BOOST_FUSION_GPU_ENABLED
            data(Sequence&& seq, detail::integer_sequence<std::size_t, 0, N...>)
                : elem(forward_at_c<0>(seq))
                , base(forward_at_c<N>(seq)...)
            {}

            template <typename Head_, typename ...Tail_>
            BOOST_FUSION_GPU_ENABLED
            data(Head_&& head, Tail_&&... tail)
                : elem(std::forward<Head_>(head))
                , base(std::forward<Tail_>(tail)...)
            {}

            BOOST_FUSION_GPU_ENABLED
            data&
            operator=(data const& rhs)
            {
                elem::operator=(static_cast<elem const&>(rhs));
                base::operator=(static_cast<base const&>(rhs));
                return *this;
            }

            BOOST_FUSION_GPU_ENABLED
            data&
            operator=(data&& rhs)
            {
                elem::operator=(std::forward<elem>(rhs));
                base::operator=(std::forward<base>(rhs));
                return *this;
            }

            template <typename Head_, typename ...Tail_>
            BOOST_FUSION_GPU_ENABLED
            void
            assign(Head_&& head, Tail_&&... tail)
            {
                static_cast<elem&>(*this) = std::forward<Head_>(head);
                base::assign(std::forward<Tail_>(tail)...);
            }
        };

        template <typename ...T>
        struct vector_data;

        template <>
        struct vector_data<>
            : data<0>, sequence_base<vector_data<> >
        {
            typedef vector_tag                  fusion_tag;
            typedef fusion_sequence_tag         tag; // this gets picked up by MPL
            typedef mpl::false_                 is_view;
            typedef random_access_traversal_tag category;

            typedef data<0> data;

            BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
            vector_data() BOOST_NOEXCEPT
            {}

            // To accept nil (and any other type which like a nil).
            template <typename Sequence>
            BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
            vector_data(Sequence const&) BOOST_NOEXCEPT
            {}

            // Due to no data, move assign ctor/op are unnecessary.

            BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
            vector_data(vector_data const& rhs) BOOST_NOEXCEPT
                : data(static_cast<data const&>(rhs))
            {}

            BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
            vector_data&
            operator=(vector_data const& rhs) BOOST_NOEXCEPT
            {
                data::operator=(static_cast<data const&>(rhs));
                return *this;
            }
        };

        template <typename ...T>
        struct vector_data
            : data<0, T...>, sequence_base<vector_data<T...> >
        {
            typedef vector_tag                  fusion_tag;
            typedef fusion_sequence_tag         tag; // this gets picked up by MPL
            typedef mpl::false_                 is_view;
            typedef random_access_traversal_tag category;

            typedef vector_detail::data<0, T...> data;

            BOOST_FUSION_GPU_ENABLED
            vector_data()
            {}

            BOOST_FUSION_GPU_ENABLED
            vector_data(vector_data const& rhs)
                : data(static_cast<data const&>(rhs))
            {}

            BOOST_FUSION_GPU_ENABLED
            vector_data(vector_data&& rhs)
                : data(std::forward<data>(rhs))
            {}

            template <typename Sequence>
            BOOST_FUSION_GPU_ENABLED
            vector_data(Sequence&& rhs
                 , typename enable_if<
                       is_base_of<vector_data, typename traits::pure<Sequence>::type>
                   >::type* = 0)
                : data(as_base<data>(std::forward<Sequence>(rhs)))
            {}

            template <typename Sequence>
            BOOST_FUSION_GPU_ENABLED
            vector_data(Sequence&& rhs
                 , typename disable_if<
                       is_base_of<vector_data, typename traits::pure<Sequence>::type>
                   >::type* = 0
                 , typename enable_if<
                       fusion::traits::is_sequence<typename remove_reference<Sequence>::type>
                   >::type* = 0)
                : data(std::forward<Sequence>(rhs)
                     , typename make_indices_from_seq<Sequence>::type())
            {}

            template <typename ...U>
            BOOST_FUSION_GPU_ENABLED
            explicit
            vector_data(U&&... var)
                : data(std::forward<U>(var)...)
            {}

            BOOST_FUSION_GPU_ENABLED
            vector_data&
            operator=(vector_data const& rhs)
            {
                data::operator=(static_cast<data const&>(rhs));
                return *this;
            }

            BOOST_FUSION_GPU_ENABLED
            vector_data&
            operator=(vector_data&& rhs)
            {
                data::operator=(std::forward<data>(rhs));
                return *this;
            }

            template <typename Sequence, std::size_t ...N>
            BOOST_FUSION_GPU_ENABLED
            void
            assign(Sequence&& rhs, detail::integer_sequence<std::size_t, N...>)
            {
                data::assign(forward_at_c<N>(rhs)...);
            }

            template <typename Sequence>
            BOOST_FUSION_GPU_ENABLED
            typename enable_if<
                is_base_of<vector_data, typename traits::pure<Sequence>::type>
              , vector_data&
            >::type
            operator=(Sequence&& rhs)
            {
                data::operator=(as_base<data>(std::forward<Sequence>(rhs)));
                return *this;
            }

            template <typename Sequence>
            BOOST_FUSION_GPU_ENABLED
            typename lazy_disable_if<
                is_base_of<vector_data, typename traits::pure<Sequence>::type>
              , enable_if<
                    fusion::traits::is_sequence<typename remove_reference<Sequence>::type>
                  , vector_data&
                >
            >::type
            operator=(Sequence&& rhs)
            {
                typedef typename
                    make_indices_from_seq<Sequence>::type
                indices;

                assign(std::forward<Sequence>(rhs), indices());
                return *this;
            }

            typedef extension::value_at_impl<vector_tag> value_at_impl;

            template <typename I>
            BOOST_FUSION_GPU_ENABLED
            typename value_at_impl::template apply<vector_data, I>::type&
            at_impl(I)
            {
                typedef typename value_at_impl::template apply<vector_data, I>::type U;
                typedef store<I::value, U> S;
                return static_cast<S*>(this)->get();
            }

            template <typename I>
            BOOST_FUSION_GPU_ENABLED
            typename value_at_impl::template apply<vector_data, I>::type const&
            at_impl(I) const
            {
                typedef typename value_at_impl::template apply<vector_data, I>::type U;
                typedef store<I::value, U> S;
                return static_cast<S const*>(this)->get();
            }
        };

        // Internal use only specialization for implementing vectorN.
        // Simple aliasing (like a using vectorN = vector<T...>) will cause specialization confliction
        // like following.
        //
        //  template <typename> struct SomeClass;
        //  template <typename T> struct SomeClass<vector<T>> { ... };
        //  template <typename T>
        //  struct SomeClass<vector1<T>> // Error, since vector<T> and vector1<T> are exact same type.
        //  { ... };
        //
        // Introducing `numbered_vector_tag` will resolve such specialization error.
        //
        //  template <typename T>
        //  struct SomeClass<vector<T>> { ... };
        //  template <typename T>
        //  struct SomeClass<vector1<T>> // OK
        //  { ... };
        //
        //  // Same meaning as above specialization.
        //  template <typename T>
        //  struct SomeClass<vector<numbered_vector_tag<1>, T>>
        //  { ... };
        template <std::size_t N, typename ...T>
        struct vector_data<numbered_vector_tag<N>, T...>
            : vector_data<T...>
        {
            typedef vector_data<T...> base;

            BOOST_STATIC_ASSERT((base::size::value == N));

            BOOST_FUSION_GPU_ENABLED
            vector_data()
            {}

            BOOST_FUSION_GPU_ENABLED
            vector_data(vector_data const& rhs)
                : base(static_cast<base const &>(rhs))
            {}

            BOOST_FUSION_GPU_ENABLED
            vector_data(vector_data&& rhs)
                : base(std::forward<base>(rhs))
            {}

            template <typename ...U>
            BOOST_FUSION_GPU_ENABLED
            vector_data(U&&... var)
                : base(std::forward<U>(var)...)
            {}

            BOOST_FUSION_GPU_ENABLED
            vector_data &
            operator=(vector_data const& rhs)
            {
                base::operator=(static_cast<base const&>(rhs));
                return *this;
            }

            BOOST_FUSION_GPU_ENABLED
            vector_data &
            operator=(vector_data&& rhs)
            {
                base::operator=(std::forward<base>(rhs));
                return *this;
            }

            using base::operator=;
        };

        template <typename D, typename... T>
        struct construct_vector_;

        template <typename D>
        struct construct_vector_<D> { typedef D type; };

        template <typename... U, typename... Tail>
        struct construct_vector_<vector_data<U...>, void_, Tail...>
            : construct_vector_<vector_data<U...> > {};

        template <typename... U, typename Head, typename... Tail>
        struct construct_vector_<vector_data<U...>, Head, Tail...>
            : construct_vector_<vector_data<U..., Head>, Tail...> {};

        template <typename... T>
        struct construct_vector : construct_vector_<vector_detail::vector_data<>, T...> {};
    }

    // This class provides backward compatibility: vector<T, ..., void_, void_, ...>.
    template <typename... T>
    struct vector
        : vector_detail::construct_vector<T...>::type
    {
        typedef typename vector_detail::construct_vector<T...>::type base;

        BOOST_FUSION_GPU_ENABLED
        vector()
        {}

        BOOST_FUSION_GPU_ENABLED
        vector(vector const& rhs)
            : base(static_cast<base const&>(rhs))
        {}

        BOOST_FUSION_GPU_ENABLED
        vector(vector&& rhs)
            : base(std::forward<base>(rhs))
        {}

        // rvalue-references is required here in order to forward any arguments to
        // base: vector(T const&...) doesn't work with trailing void_ and
        // vector(U const&...) cannot forward any arguments to base.
        template <typename... U>
        BOOST_FUSION_GPU_ENABLED
        vector(U&&... u)
            : base(std::forward<U>(u)...)
        {}

        BOOST_FUSION_GPU_ENABLED
        vector&
        operator=(vector const& rhs)
        {
            base::operator=(static_cast<base const&>(rhs));
            return *this;
        }

        BOOST_FUSION_GPU_ENABLED
        vector&
        operator=(vector&& rhs)
        {
            base::operator=(std::forward<base>(rhs));
            return *this;
        }

        using base::operator=;
    };
}}

#endif
#endif


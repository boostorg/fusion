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
#include <boost/mpl/vector.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <cstddef>
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
#include <boost/mpl/if.hpp>
#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/type_traits/is_rvalue_reference.hpp>
#include <utility>
#else
#include <boost/fusion/support/detail/access.hpp>
#endif
#if !defined(BOOST_MPL_HAS_VARIADIC_VECTOR)
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/mpl/vector/vector20.hpp>
#include <boost/mpl/vector/vector30.hpp>
#include <boost/mpl/vector/vector40.hpp>
#include <boost/mpl/vector/vector50.hpp>
#endif

namespace boost { namespace fusion
{
    struct vector_tag;
    struct random_access_traversal_tag;

    namespace vector_detail
    {
        // XXX: We are waiting MPL11...
#if !defined(BOOST_MPL_HAS_VARIADIC_VECTOR)
        template <std::size_t I, typename ...T>
        struct mpl_vector_;

#define FUSION_MPL_VECTOR_SELECTOR_SPECIALIZATION(z, N, d)                  \
        template <typename ...T>                                            \
        struct mpl_vector_<BOOST_PP_INC(N), T...>                           \
        {                                                                   \
            typedef mpl::BOOST_PP_CAT(vector, BOOST_PP_INC(N))<T...> type;  \
        };

        BOOST_PP_REPEAT(50, FUSION_MPL_VECTOR_SELECTOR_SPECIALIZATION, ~)
#endif

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

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
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
            return base;
        }
#endif

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

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
            BOOST_FUSION_GPU_ENABLED
            store(store&& rhs)
                : elem(std::forward<T>(rhs.get()))
            {}

            template <typename U>
            BOOST_FUSION_GPU_ENABLED
            store(U&& rhs
                , typename enable_if<
                      is_convertible<typename traits::remove_rvalue_reference<U>::type, T>
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

            BOOST_FUSION_GPU_ENABLED
            store&
            operator=(store&& rhs)
            {
                elem = std::forward<T>(rhs.get());
                return *this;
            }
#else
            BOOST_FUSION_GPU_ENABLED
            store(typename detail::call_param<T>::type rhs)
                : elem(rhs)
            {}

            BOOST_FUSION_GPU_ENABLED
            store&
            operator=(typename detail::call_param<T>::type rhs)
            {
                elem = rhs;
                return *this;
            }
#endif

            BOOST_FUSION_GPU_ENABLED
            store&
            operator=(store const& rhs)
            {
                elem = rhs.get();
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

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
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
#else
            template <typename Sequence, std::size_t ...N>
            BOOST_FUSION_GPU_ENABLED
            data(Sequence const& seq, detail::integer_sequence<std::size_t, 0, N...>)
                : elem(vector_detail::mandatory_at_c<0>(seq))
                , base(vector_detail::mandatory_at_c<N>(seq)...)
            {}

            template <typename Sequence, std::size_t ...N>
            BOOST_FUSION_GPU_ENABLED
            data(Sequence& seq, detail::integer_sequence<std::size_t, 0, N...>)
                : elem(vector_detail::mandatory_at_c<0>(seq))
                , base(vector_detail::mandatory_at_c<N>(seq)...)
            {}

            BOOST_FUSION_GPU_ENABLED
            data(typename detail::call_param<T>::type head
               , typename detail::call_param<Tail>::type... tail)
                : elem(head), base(tail...)
            {}
#endif

            BOOST_FUSION_GPU_ENABLED
            data&
            operator=(data const& rhs)
            {
                elem::operator=(static_cast<elem const&>(rhs));
                base::operator=(static_cast<base const&>(rhs));
                return *this;
            }

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
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
#else
            BOOST_FUSION_GPU_ENABLED
            void
            assign(typename detail::call_param<T>::type head
                 , typename detail::call_param<Tail>::type... tail)
            {
                static_cast<elem&>(*this) = head;
                base::assign(tail...);
            }
#endif
        };
    }

    template <>
    struct vector<>
        : vector_detail::data<0>
        , sequence_base<vector<> >
    {
        typedef vector_tag                  fusion_tag;
        typedef fusion_sequence_tag         tag; // this gets picked up by MPL
        typedef mpl::false_                 is_view;
        typedef random_access_traversal_tag category;

        typedef mpl::vector<> types;
        typedef vector_detail::data<0> data;

        BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        vector() BOOST_NOEXCEPT
        {}

        // To accept nil (and any other type which like a nil).
        template <typename Sequence>
        BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        vector(Sequence const&) BOOST_NOEXCEPT
        {}

        // Due to no data, move assign ctor/op are unnecessary.

        BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        vector(vector const& rhs) BOOST_NOEXCEPT
            : data(static_cast<data const&>(rhs))
        {}

        BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        vector&
        operator=(vector const& rhs) BOOST_NOEXCEPT
        {
            data::operator=(static_cast<data const&>(rhs));
            return *this;
        }
    };

    template <typename ...T>
    struct vector
        : vector_detail::data<0, T...>
        , sequence_base<vector<T...> >
    {
        typedef vector_tag                  fusion_tag;
        typedef fusion_sequence_tag         tag; // this gets picked up by MPL
        typedef mpl::false_                 is_view;
        typedef random_access_traversal_tag category;

#if !defined(BOOST_MPL_HAS_VARIADIC_VECTOR)
        typedef typename
            vector_detail::mpl_vector_<sizeof...(T), T...>::type
        types;
#else
        typedef mpl::vector<T...> types;
#endif
        typedef vector_detail::data<0, T...> data;

        BOOST_FUSION_GPU_ENABLED
        vector()
        {}

        BOOST_FUSION_GPU_ENABLED
        vector(vector const& rhs)
            : data(static_cast<data const&>(rhs))
        {}

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
        BOOST_FUSION_GPU_ENABLED
        vector(vector&& rhs)
            : data(std::forward<data>(rhs))
        {}

        template <typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        vector(Sequence&& rhs
             , typename enable_if<
                   is_base_of<vector, typename vector_detail::traits::pure<Sequence>::type>
               >::type* = 0)
            : data(vector_detail::as_base<data>(std::forward<Sequence>(rhs)))
        {}

        template <typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        vector(Sequence&& rhs
             , typename disable_if<
                   is_base_of<vector, typename vector_detail::traits::pure<Sequence>::type>
               >::type* = 0
             , typename enable_if<
                   traits::is_sequence<typename remove_reference<Sequence>::type>
               >::type* = 0)
            : data(std::forward<Sequence>(rhs)
                 , typename vector_detail::make_indices_from_seq<Sequence>::type())
        {}

        template <typename ...U>
        BOOST_FUSION_GPU_ENABLED
        explicit
        vector(U&&... var)
            : data(std::forward<U>(var)...)
        {}
#else
        template <typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        vector(Sequence const& rhs
             , typename enable_if<is_base_of<vector, Sequence> >::type* = 0)
            : data(static_cast<data const&>(rhs))
        {}

        template <typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        vector(Sequence& rhs
             , typename enable_if<is_base_of<vector, Sequence> >::type* = 0)
            : data(static_cast<data const&>(rhs))
        {}

        template <typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        vector(Sequence const& rhs
             , typename disable_if<is_base_of<vector, Sequence> >::type* = 0
             , typename enable_if<traits::is_sequence<Sequence> >::type* = 0)
            : data(rhs, typename vector_detail::make_indices_from_seq<Sequence>::type())
        {}

        template <typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        vector(Sequence& rhs
             , typename disable_if<is_base_of<vector, Sequence> >::type* = 0
             , typename enable_if<traits::is_sequence<Sequence> >::type* = 0)
            : data(rhs, typename vector_detail::make_indices_from_seq<Sequence>::type())
        {}

        BOOST_FUSION_GPU_ENABLED
        explicit
        vector(typename detail::call_param<T>::type... var)
            : data(var...)
        {}
#endif

        BOOST_FUSION_GPU_ENABLED
        vector&
        operator=(vector const& rhs)
        {
            data::operator=(static_cast<data const&>(rhs));
            return *this;
        }

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
        BOOST_FUSION_GPU_ENABLED
        vector&
        operator=(vector&& rhs)
        {
            data::operator=(std::forward<data>(rhs));
            return *this;
        }

        template <typename Sequence, std::size_t ...N>
        BOOST_FUSION_GPU_ENABLED
        void
        assign(Sequence&& rhs, detail::integer_sequence<std::size_t, N...>)
        {
            data::assign(vector_detail::forward_at_c<N>(rhs)...);
        }

        template <typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        typename enable_if<
            is_base_of<vector, typename vector_detail::traits::pure<Sequence>::type>
          , vector&
        >::type
        operator=(Sequence&& rhs)
        {
            data::operator=(vector_detail::as_base<data>(std::forward<Sequence>(rhs)));
            return *this;
        }

        template <typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        typename lazy_disable_if<
            is_base_of<vector, typename vector_detail::traits::pure<Sequence>::type>
          , enable_if<
                traits::is_sequence<typename remove_reference<Sequence>::type>
              , vector&
            >
        >::type
        operator=(Sequence&& rhs)
        {
            typedef typename
                vector_detail::make_indices_from_seq<Sequence>::type
            indices;

            assign(std::forward<Sequence>(rhs), indices());
            return *this;
        }
#else
        template <typename Sequence, std::size_t ...N>
        BOOST_FUSION_GPU_ENABLED
        void
        assign(Sequence const& rhs, detail::integer_sequence<std::size_t, N...>)
        {
            data::assign(vector_detail::mandatory_at_c<N>(rhs)...);
        }

        template <typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        typename enable_if<is_base_of<vector, Sequence>, vector&>::type
        operator=(Sequence const& rhs)
        {
            data::operator=(static_cast<data const&>(rhs));
            return *this;
        }

        template <typename Sequence>
        BOOST_FUSION_GPU_ENABLED
        typename lazy_disable_if<
            is_base_of<vector, Sequence>
          , enable_if<traits::is_sequence<Sequence>, vector&>
        >::type
        operator=(Sequence const& rhs)
        {
            typedef typename
                vector_detail::make_indices_from_seq<Sequence>::type
            indices;

            assign(rhs, indices());
            return *this;
        }
#endif

        template <typename I>
        BOOST_FUSION_GPU_ENABLED
        typename mpl::at<types, I>::type&
        at_impl(I)
        {
            typedef typename mpl::at<types, I>::type U;
            typedef vector_detail::store<I::value, U> S;
            return static_cast<S*>(this)->get();
        }

        template <typename I>
        BOOST_FUSION_GPU_ENABLED
        typename mpl::at<types, I>::type const&
        at_impl(I) const
        {
            typedef typename mpl::at<types, I>::type U;
            typedef vector_detail::store<I::value, U> S;
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
    struct vector<numbered_vector_tag<N>, T...>
        : vector<T...>
    {
        typedef vector<T...> base;

        BOOST_STATIC_ASSERT((sizeof...(T) == N));

/*
 * Boost.Config exports no macros for inheriting ctor availiability
#if !defined(BOOST_NO_CXX11_INHERITING_CTOR)
        BOOST_FUSION_GPU_ENABLED
        vector()
        {}

        using base::base;
#elif !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
*/
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
        BOOST_FUSION_GPU_ENABLED
        vector()
        {}

        template <typename ...U>
        BOOST_FUSION_GPU_ENABLED
        vector(U&&... var)
            : base(std::forward<U>(var)...)
        {}
#else
        BOOST_FUSION_GPU_ENABLED
        explicit
        vector(typename detail::call_param<T>::type... var)
            : base(var...)
        {}

        template <typename Sequence>
        vector(Sequence const& seq)
            : base(seq)
        {}

        template <typename Sequence>
        vector(Sequence& seq)
            : base(seq)
        {}
#endif

        BOOST_FUSION_GPU_ENABLED
        vector(vector const& rhs)
            : base(static_cast<base const&>(rhs))
        {}

        BOOST_FUSION_GPU_ENABLED
        vector&
        operator=(vector const& rhs)
        {
            base::operator=(static_cast<base const&>(rhs));
            return *this;
        }

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
        BOOST_FUSION_GPU_ENABLED
        vector(vector&& rhs)
            : base(std::forward<base>(rhs))
        {}

        BOOST_FUSION_GPU_ENABLED
        vector&
        operator=(vector&& rhs)
        {
            base::operator=(std::forward<base>(rhs));
            return *this;
        }
#endif

        using base::operator=;
    };
}}

#endif
#endif


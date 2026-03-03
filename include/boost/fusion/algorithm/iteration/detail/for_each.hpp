/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef FUSION_FOR_EACH_05052005_1028
#define FUSION_FOR_EACH_05052005_1028

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/sequence/intrinsic/begin.hpp>
#include <boost/fusion/sequence/intrinsic/end.hpp>
#include <boost/fusion/iterator/equal_to.hpp>
#include <boost/fusion/iterator/next.hpp>
#include <boost/fusion/iterator/deref.hpp>
#include <boost/fusion/iterator/distance.hpp>
#include <boost/fusion/support/category_of.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <boost/utility/declval.hpp>
#include <boost/mpl/bool.hpp>

namespace boost { namespace fusion {
namespace detail
{
#if defined(BOOST_FUSION_HAS_INDEXED_FOREACH)
#if defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template<typename T, typename F, typename I, typename = decltype(boost::declval<F>()(boost::declval<T>(), I{}))>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline void
    for_each_apply(T& value, F& f, I i, long)
    {
        f(value, i);
    }

    template<typename T, typename F, typename I, typename = decltype(boost::declval<F>()(boost::declval<T>(), I{}))>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline void
    for_each_apply(T const& value, F& f, I i, long)
    {
        f(value, i);
    }
#else
    template<typename T, typename F, typename I, typename = decltype(boost::declval<F>()(boost::declval<T>(), I{}))>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline void
    for_each_apply(T&& value, F& f, I i, long)
    {
        f(std::forward<T>(value), i);
    }
#endif
#endif

#if defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    template<typename T, typename F, typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline void
    for_each_apply(T& value, F& f, I /*i*/, int)
    {
        f(value);
    }

    template<typename T, typename F, typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline void
    for_each_apply(T const& value, F& f, I /*i*/, int)
    {
        f(value);
    }
#else
    template<typename T, typename F, typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline void
    for_each_apply(T&& value, F& f, I /*i*/, int)
    {
        f(std::forward<T>(value));
    }
#endif

    template <typename First, typename Last, typename F, typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline void
    for_each_linear(First const&, Last const&, F const&, mpl::true_, I /*i*/)
    {
    }

    template <typename First, typename Last, typename F, typename I>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline void
    for_each_linear(First const& first, Last const& last, F& f, mpl::false_, I i)
    {
        for_each_apply(*first, f, i, 1L);
        detail::for_each_linear(fusion::next(first), last, f, 
                                result_of::equal_to<typename result_of::next<First>::type, Last>(),
                                boost::integral_constant<int, I::value + 1>());
    }


    template <typename Sequence, typename F, typename Tag>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline void
    for_each_dispatch(Sequence& seq, F& f, Tag)
    {
        detail::for_each_linear(
                                fusion::begin(seq)
                                , fusion::end(seq)
                                , f
                                , result_of::equal_to<
                                typename result_of::begin<Sequence>::type
                                , typename result_of::end<Sequence>::type>()
                                , boost::integral_constant<int, 0>());
    }

    template<int N, int S=0>
    struct for_each_unrolled
    {
        template<typename I0, typename F>
        BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        static void call(I0 const& i0, F& f)
        {
            for_each_apply(*i0, f, boost::integral_constant<int, S + 0>(), 1L);
            typedef typename result_of::next<I0>::type I1;
            I1 i1(fusion::next(i0));
            for_each_apply(*i1, f, boost::integral_constant<int, S + 1>(), 1L);
            typedef typename result_of::next<I1>::type I2;
            I2 i2(fusion::next(i1));
            for_each_apply(*i2, f, boost::integral_constant<int, S + 2>(), 1L);
            typedef typename result_of::next<I2>::type I3;
            I3 i3(fusion::next(i2));
            for_each_apply(*i3, f, boost::integral_constant<int, S + 3>(), 1L);
            for_each_unrolled<N-4, S+4>::call(fusion::next(i3), f);
        }
    };

    template<int S>
    struct for_each_unrolled<3, S>
    {
        template<typename I0, typename F>
        BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        static void call(I0 const& i0, F& f)
        {
            for_each_apply(*i0, f, boost::integral_constant<int, S + 0>(), 1L);
            typedef typename result_of::next<I0>::type I1;
            I1 i1(fusion::next(i0));
            for_each_apply(*i1, f, boost::integral_constant<int, S + 1>(), 1L);
            typedef typename result_of::next<I1>::type I2;
            I2 i2(fusion::next(i1));
            for_each_apply(*i2, f, boost::integral_constant<int, S + 2>(), 1L);
        }
    };

    template<int S>
    struct for_each_unrolled<2, S>
    {
        template<typename I0, typename F>
        BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        static void call(I0 const& i0, F& f)
        {
            for_each_apply(*i0, f, boost::integral_constant<int, S + 0>(), 1L);
            typedef typename result_of::next<I0>::type I1;
            I1 i1(fusion::next(i0));
            for_each_apply(*i1, f, boost::integral_constant<int, S + 1>(), 1L);
        }
    };

    template<int S>
    struct for_each_unrolled<1, S>
    {
        template<typename I0, typename F>
        BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        static void call(I0 const& i0, F& f)
        {
            for_each_apply(*i0, f, boost::integral_constant<int, S + 0>(), 1L);
        }
    };

    template<int S>
    struct for_each_unrolled<0, S>
    {
        template<typename It, typename F>
        BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        static void call(It const&, F const&)
        {
        }
    };

    template <typename Sequence, typename F>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline void
    for_each_dispatch(Sequence& seq, F& f, random_access_traversal_tag)
    {
        typedef typename result_of::begin<Sequence>::type begin;
        typedef typename result_of::end<Sequence>::type end;
        for_each_unrolled<result_of::distance<begin, end>::type::value>::call(fusion::begin(seq), f);
    }

    template <typename Sequence, typename F>
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline void
    for_each(Sequence& seq, F& f, mpl::false_) // unsegmented implementation
    {
        detail::for_each_dispatch(seq, f, typename traits::category_of<Sequence>::type());
    }
}}}


#endif


/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2006 Dan Marsden
    Copyright (c) 2009-2010 Christopher Schmidt
    Copyright (c) 2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/preprocessor/cat.hpp>

#ifdef BOOST_FUSION_REVERSE_FOLD
#   ifdef BOOST_FUSION_ITER_FOLD
#       define BOOST_FUSION_FOLD_NAME reverse_iter_fold
#   else
#       define BOOST_FUSION_FOLD_NAME reverse_fold
#   endif

#   define BOOST_FUSION_FOLD_IMPL_FIRST_IT_FUNCTION end
#   define BOOST_FUSION_FOLD_IMPL_NEXT_IT_FUNCTION prior
#   define BOOST_FUSION_FOLD_IMPL_FIRST_IT_META_TRANSFORM(IT)                   \
        typename fusion::result_of::prior<IT>::type
#   define BOOST_FUSION_FOLD_IMPL_FIRST_IT_TRANSFORM(IT) fusion::prior(IT)
#else
#   ifdef BOOST_FUSION_ITER_FOLD
#       define BOOST_FUSION_FOLD_NAME iter_fold
#   else
#       define BOOST_FUSION_FOLD_NAME fold
#   endif

#   define BOOST_FUSION_FOLD_IMPL_FIRST_IT_FUNCTION begin
#   define BOOST_FUSION_FOLD_IMPL_NEXT_IT_FUNCTION next
#   define BOOST_FUSION_FOLD_IMPL_FIRST_IT_META_TRANSFORM(IT) IT
#   define BOOST_FUSION_FOLD_IMPL_FIRST_IT_TRANSFORM(IT) IT
#endif
#ifdef BOOST_FUSION_ITER_FOLD
#   define BOOST_FUSION_FOLD_IMPL_INVOKE_IT_META_TRANSFORM(IT) IT&
#   define BOOST_FUSION_FOLD_IMPL_INVOKE_IT_TRANSFORM(IT) IT
#else
#   define BOOST_FUSION_FOLD_IMPL_INVOKE_IT_META_TRANSFORM(IT)                  \
        typename fusion::result_of::deref<IT>::type
#   define BOOST_FUSION_FOLD_IMPL_INVOKE_IT_TRANSFORM(IT) fusion::deref(IT)
#endif

namespace boost { namespace fusion
{
    namespace detail
    {
        template<int SeqSize, typename It, typename State, typename F, typename = void>
        struct BOOST_PP_CAT(result_of_it_,BOOST_FUSION_FOLD_NAME)
        {};

        template<typename It, typename State, typename F>
        struct BOOST_PP_CAT(result_of_it_,BOOST_FUSION_FOLD_NAME)<0,It,State,F
          , typename boost::enable_if_has_type<typename State::type>::type>
        {
            typedef typename State::type type;
        };

        template<int SeqSize, typename It, typename State, typename F>
        struct BOOST_PP_CAT(result_of_it_,BOOST_FUSION_FOLD_NAME)<SeqSize,It,State,F
          , typename boost::enable_if_has_type<typename State::type>::type>
          : BOOST_PP_CAT(result_of_it_,BOOST_FUSION_FOLD_NAME)<
                SeqSize-1
              , typename result_of::BOOST_FUSION_FOLD_IMPL_NEXT_IT_FUNCTION<It>::type
              , boost::result_of<
                    F(
                        typename State::type const&,
                        BOOST_FUSION_FOLD_IMPL_INVOKE_IT_META_TRANSFORM(It const)
                    )
                >
              , F
            >
        {};

        template<typename It, typename State, typename F>
        BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        inline typename BOOST_PP_CAT(result_of_it_,BOOST_FUSION_FOLD_NAME)<
            0
          , It
          , State
          , F
        >::type
        BOOST_PP_CAT(it_,BOOST_FUSION_FOLD_NAME)(mpl::int_<0>, It const&, typename State::type state, F&)
        {
            return state;
        }

        template<typename It, typename State, typename F, int SeqSize>
        BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        inline typename lazy_enable_if_c<
            SeqSize != 0
          , BOOST_PP_CAT(result_of_it_,BOOST_FUSION_FOLD_NAME)<
                SeqSize
              , It
              , State
              , F
            >
        >::type
        BOOST_PP_CAT(it_,BOOST_FUSION_FOLD_NAME)(mpl::int_<SeqSize>, It const& it, typename State::type state, F& f)
        {
            return BOOST_PP_CAT(it_,BOOST_FUSION_FOLD_NAME)<
                typename result_of::BOOST_FUSION_FOLD_IMPL_NEXT_IT_FUNCTION<It>::type
              , boost::result_of<
                    F(
                        typename State::type const&,
                        BOOST_FUSION_FOLD_IMPL_INVOKE_IT_META_TRANSFORM(It const)
                    )
                >
              , F
            >(
                mpl::int_<SeqSize-1>()
              , fusion::BOOST_FUSION_FOLD_IMPL_NEXT_IT_FUNCTION(it)
              , f(state, BOOST_FUSION_FOLD_IMPL_INVOKE_IT_TRANSFORM(it))
              , f
            );
        }

        template<typename Seq, typename State, typename F
          , bool = traits::is_sequence<Seq>::value
          , bool = traits::is_segmented<Seq>::value>
        struct BOOST_PP_CAT(result_of_,BOOST_FUSION_FOLD_NAME)
        {};

        template<typename Seq, typename State, typename F>
        struct BOOST_PP_CAT(result_of_,BOOST_FUSION_FOLD_NAME)<Seq, State, F, true, false>
          : BOOST_PP_CAT(result_of_it_,BOOST_FUSION_FOLD_NAME)<
                result_of::size<Seq>::value
              , BOOST_FUSION_FOLD_IMPL_FIRST_IT_META_TRANSFORM(
                    typename result_of::BOOST_FUSION_FOLD_IMPL_FIRST_IT_FUNCTION<Seq>::type
                )
              , add_reference<typename add_const<State>::type>
              , F
            >
        {};

        template<typename Seq, typename State, typename F>
        BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
        inline typename BOOST_PP_CAT(result_of_,BOOST_FUSION_FOLD_NAME)<Seq, State, F>::type
        BOOST_FUSION_FOLD_NAME(Seq& seq, State& state, F& f)
        {
            return BOOST_PP_CAT(it_,BOOST_FUSION_FOLD_NAME)<
                BOOST_FUSION_FOLD_IMPL_FIRST_IT_META_TRANSFORM(
                    typename result_of::BOOST_FUSION_FOLD_IMPL_FIRST_IT_FUNCTION<Seq>::type
                )
              , add_reference<typename add_const<State>::type>
              , F
            >(
                typename result_of::size<Seq>::type()
              , BOOST_FUSION_FOLD_IMPL_FIRST_IT_TRANSFORM(
                    fusion::BOOST_FUSION_FOLD_IMPL_FIRST_IT_FUNCTION(seq)
                )
              , state
              , f
            );
        }
    }

    namespace result_of
    {
        template<typename Seq, typename State, typename F>
        struct BOOST_FUSION_FOLD_NAME
          : detail::BOOST_PP_CAT(result_of_,BOOST_FUSION_FOLD_NAME)<Seq, State, F>
        {};
    }

    template<typename Seq, typename State, typename F>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline typename result_of::BOOST_FUSION_FOLD_NAME<
        Seq
      , State const
      , F
    >::type
    BOOST_FUSION_FOLD_NAME(Seq& seq, State const& state, F f)
    {
        return detail::BOOST_FUSION_FOLD_NAME<Seq, State const, F>(seq, state, f);
    }

    template<typename Seq, typename State, typename F>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline typename result_of::BOOST_FUSION_FOLD_NAME<
        Seq const
      , State const
      , F
    >::type
    BOOST_FUSION_FOLD_NAME(Seq const& seq, State const& state, F f)
    {
        return detail::BOOST_FUSION_FOLD_NAME<Seq const, State const, F>(seq, state, f);
    }

    template<typename Seq, typename State, typename F>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline typename result_of::BOOST_FUSION_FOLD_NAME<
        Seq
      , State const
      , F
    >::type
    BOOST_FUSION_FOLD_NAME(Seq& seq, State& state, F f)
    {
        return detail::BOOST_FUSION_FOLD_NAME<Seq, State, F>(seq, state, f);
    }

    template<typename Seq, typename State, typename F>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline typename result_of::BOOST_FUSION_FOLD_NAME<
        Seq const
      , State const
      , F
    >::type
    BOOST_FUSION_FOLD_NAME(Seq const& seq, State& state, F f)
    {
        return detail::BOOST_FUSION_FOLD_NAME<Seq const, State, F>(seq, state, f);
    }
}}

#undef BOOST_FUSION_FOLD_NAME
#undef BOOST_FUSION_FOLD_IMPL_FIRST_IT_FUNCTION
#undef BOOST_FUSION_FOLD_IMPL_NEXT_IT_FUNCTION
#undef BOOST_FUSION_FOLD_IMPL_FIRST_IT_META_TRANSFORM
#undef BOOST_FUSION_FOLD_IMPL_FIRST_IT_TRANSFORM
#undef BOOST_FUSION_FOLD_IMPL_INVOKE_IT_META_TRANSFORM
#undef BOOST_FUSION_FOLD_IMPL_INVOKE_IT_TRANSFORM

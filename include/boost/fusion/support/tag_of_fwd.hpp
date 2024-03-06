/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_FUSION_TAG_OF_FWD_31122005_1445
#define BOOST_FUSION_TAG_OF_FWD_31122005_1445

namespace boost { namespace fusion
{
    namespace detail
    {
        // This metafunction mustn't have more than one specialization in the whole Fusion
        template<typename T, typename Active = void>
        struct tag_of_fallback;
    }
    namespace traits
    {
        template<typename T, typename Active = void>
        struct tag_of;
    }
}}

#endif

/*=============================================================================
    Copyright (c) 2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

// Mock fallback used in old compilers.

#include <boost/mpl/integral_c.hpp>
#include <boost/type_traits/enable_if.hpp>

template<typename T>
struct my_is_implicitly_reflectable : boost::mpl::integral_c<bool, (sizeof(T) > 0)> {
};

namespace boost { namespace fusion
{
    struct boost_my_reflectable_tag;
    namespace detail
    {
        template<typename Sequence>
        struct tag_of_fallback<Sequence, typename boost::enable_if<my_is_implicitly_reflectable<Sequence> >::type>
        {
            typedef boost_my_reflectable_tag type;
        };
    }
}}


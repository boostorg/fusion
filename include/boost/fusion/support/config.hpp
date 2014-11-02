/*=============================================================================
    Copyright (c) 2014 Eric Niebler
    Copyright (c) 2014 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_SUPPORT_CONFIG_01092014_1718)
#define FUSION_SUPPORT_CONFIG_01092014_1718

#include <boost/config.hpp>

#ifndef BOOST_FUSION_GPU_ENABLED
#define BOOST_FUSION_GPU_ENABLED BOOST_GPU_ENABLED
#endif

// Enclose with inline namespace because unqualified lookup of GCC < 4.5 is broken.
//
//      namespace detail {
//          struct foo;
//          struct X { };
//      }
//
//      template <typename T> void foo(T) { }
//
//      int main()
//      {
//            foo(detail::X());
//            // prog.cc: In function 'int main()':
//            // prog.cc:2: error: 'struct detail::foo' is not a function,
//            // prog.cc:6: error: conflict with 'template<class T> void foo(T)'
//            // prog.cc:10: error: in call to 'foo'
//      }
namespace boost { namespace fusion { namespace detail
{
    namespace barrier { }
    using namespace barrier;
}}}
#define BOOST_FUSION_BARRIER_BEGIN namespace barrier {
#define BOOST_FUSION_BARRIER_END   }

#endif

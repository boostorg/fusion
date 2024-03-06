/*=============================================================================
    Copyright (c) 2023 Denis Mikhailov
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/type_index/ctti_type_index.hpp>

namespace ns {
struct user_defined_struct {
  int first;
  int second;
};
}

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

// Function that returns name of the type without 'class ' or 'struct ' prefix
template <class T>
constexpr const char* name() noexcept {
    const char* name = boost::typeindex::ctti_type_index::type_id<T>().raw_name();

    // Some compilers add `class ` or `struct ` before the namespace, so we need to skip those words first
    if (starts_with(name, "class ")) {
        name += sizeof("class ") - 1;
    } else if (starts_with(name, "struct ")) {
        name += sizeof("struct ") - 1;
    }

    return name;
}

int main() {
  static_assert(starts_with(name<ns::user_defined_struct>(), "ns::user_defined_struct"), "");
}


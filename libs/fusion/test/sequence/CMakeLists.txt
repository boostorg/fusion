cmake_minimum_required (VERSION 2.8)
project(boost_fusion_std_array)

if(MSVC)
  list(APPEND CMAKE_CXX_FLAGS /Za)
else()
list(APPEND CMAKE_CXX_FLAGS -pedantic -Wall)
if(CMAKE_COMPILER_IS_GNUCXX)
  list(APPEND CMAKE_CXX_FLAGS -std=c++0x)
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" OR "${CMAKE_CXX_COMPILER}" MATCHES "clang")
  list(APPEND CMAKE_CXX_FLAGS -std=c++11)
endif()
endif()

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

find_package(Boost 1.54)
if (NOT Boost_FOUND)
  message(FATAL_ERROR "Cannot find Boost")
endif()
include_directories(${Boost_INCLUDE_DIRS})

add_executable(std_array std_array.cpp)

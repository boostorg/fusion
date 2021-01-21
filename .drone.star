# Use, modification, and distribution are
# subject to the Boost Software License, Version 1.0. (See accompanying
# file LICENSE.txt)
#
# Copyright Rene Rivera 2020.

# For Drone CI we use the Starlark scripting language to reduce duplication.
# As the yaml syntax for Drone CI is rather limited.
#
#
globalenv={}
linuxglobalimage="cppalliance/droneubuntu1604:1"
windowsglobalimage="cppalliance/dronevs2019"

def main(ctx):
  return [
  linux_cxx("TOOLSET=gcc-4.4 CXXSTD=98,0x Job 0", "g++", packages="g++-4.4", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'gcc-4.4', 'CXXSTD': '98,0x', 'DRONE_JOB_UUID': 'b6589fc6ab'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc-4.6 CXXSTD=03,0x Job 1", "g++", packages="g++-4.6", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'gcc-4.6', 'CXXSTD': '03,0x', 'DRONE_JOB_UUID': '356a192b79'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc-4.7 CXXSTD=03,11 Job 2", "g++", packages="g++-4.7", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'gcc-4.7', 'CXXSTD': '03,11', 'DRONE_JOB_UUID': 'da4b9237ba'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc-4.8 CXXSTD=03,11,1y Job 3", "g++", packages="g++-4.8", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'gcc-4.8', 'CXXSTD': '03,11,1y', 'DRONE_JOB_UUID': '77de68daec'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc-4.9 CXXSTD=03,11,14 Job 4", "g++", packages="g++-4.9", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'gcc-4.9', 'CXXSTD': '03,11,14', 'DRONE_JOB_UUID': '1b64538924'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc-5 CXXSTD=03,11,14,17 Job 5", "g++", packages="g++-5", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'gcc-5', 'CXXSTD': '03,11,14,17', 'DRONE_JOB_UUID': 'ac3478d69a'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc-6 CXXSTD=03,11,14,17 Job 6", "g++", packages="g++-6", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'gcc-6', 'CXXSTD': '03,11,14,17', 'DRONE_JOB_UUID': 'c1dfd96eea'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc-7 CXXSTD=03,11,14,17 Job 7", "g++", packages="g++-7", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'gcc-7', 'CXXSTD': '03,11,14,17', 'DRONE_JOB_UUID': '902ba3cda1'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc-8 CXXSTD=03,11,14,17,2a Job 8", "g++", packages="g++-8", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'gcc-8', 'CXXSTD': '03,11,14,17,2a', 'DRONE_JOB_UUID': 'fe5dbbcea5'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang-3.5 CXXSTD=03,11,14,1z Job 9", "g++", packages="clang-3.5", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'clang-3.5', 'CXXSTD': '03,11,14,1z', 'DRONE_JOB_UUID': '0ade7c2cf9'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang-3.6 CXXSTD=03,11,14,1z Job 10", "g++", packages="clang-3.6", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'clang-3.6', 'CXXSTD': '03,11,14,1z', 'DRONE_JOB_UUID': 'b1d5781111'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang-3.7 CXXSTD=03,11,14,1z Job 11", "g++", packages="clang-3.7", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'clang-3.7', 'CXXSTD': '03,11,14,1z', 'DRONE_JOB_UUID': '17ba079149'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang-3.8 CXXSTD=03,11,14,1z Job 12", "g++", packages="clang-3.8", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'clang-3.8', 'CXXSTD': '03,11,14,1z', 'DRONE_JOB_UUID': '7b52009b64'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang-3.9 CXXSTD=03,11,14,1z Job 13", "g++", packages="clang-3.9", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'clang-3.9', 'CXXSTD': '03,11,14,1z', 'DRONE_JOB_UUID': 'bd307a3ec3'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang-4.0 CXXSTD=03,11,14,1z Job 14", "g++", packages="clang-4.0", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'clang-4.0', 'CXXSTD': '03,11,14,1z', 'DRONE_JOB_UUID': 'fa35e19212'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang-5.0 CXXSTD=03,11,14,17,2a Job 15", "g++", packages="clang-5.0", llvm_os="xenial", llvm_ver="5.0", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'clang-5.0', 'CXXSTD': '03,11,14,17,2a', 'DRONE_JOB_UUID': 'f1abd67035'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang-6.0 CXXSTD=03,11,14,17,2a Job 16", "g++", packages="clang-6.0", llvm_os="xenial", llvm_ver="6.0", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'clang-6.0', 'CXXSTD': '03,11,14,17,2a', 'DRONE_JOB_UUID': '1574bddb75'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang-7.0 CXXSTD=03,11,14,17,2a Job 17", "g++", packages="clang-7", llvm_os="xenial", llvm_ver="7", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'clang-7.0', 'CXXSTD': '03,11,14,17,2a', 'DRONE_JOB_UUID': '0716d9708d'}, globalenv=globalenv),
  osx_cxx("TOOLSET=clang COMPILER=clang++ CXXSTD=03,11,1 Job 18", "clang++", packages="", buildtype="boost", buildscript="drone", environment={'TOOLSET': 'clang', 'COMPILER': 'clang++', 'CXXSTD': '03,11,14,1z', 'DRONE_JOB_UUID': '9e6a55b6b4'}, globalenv=globalenv),
    ]

# from https://github.com/boostorg/boost-ci
load("@boost_ci//ci/drone/:functions.star", "linux_cxx","windows_cxx","osx_cxx","freebsd_cxx")

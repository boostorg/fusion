#!/bin/bash

# Copyright 2020 Rene Rivera, Sam Darwin
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

set -e
export TRAVIS_BUILD_DIR=$(pwd)
export DRONE_BUILD_DIR=$(pwd)
export TRAVIS_BRANCH=$DRONE_BRANCH
export VCS_COMMIT_ID=$DRONE_COMMIT
export GIT_COMMIT=$DRONE_COMMIT
export REPO_NAME=$DRONE_REPO
export PATH=~/.local/bin:/usr/local/bin:$PATH

if [ "$DRONE_JOB_BUILDTYPE" == "boost" ]; then

echo '==================================> INSTALL'

BOOST_BRANCH=develop && [ "$TRAVIS_BRANCH" == "master" ] && BOOST_BRANCH=master || true
cd ..
git clone --depth 1 -b $BOOST_BRANCH https://github.com/boostorg/boost.git boost-root
cd boost-root
git submodule init libs/array
git submodule init libs/assert
git submodule init libs/bind
git submodule init libs/concept_check
git submodule init libs/config
git submodule init libs/container_hash
git submodule init libs/conversion
git submodule init libs/core
git submodule init libs/detail
git submodule init libs/function
git submodule init libs/function_types
git submodule init libs/functional
git submodule init libs/integer
git submodule init libs/iterator
git submodule init libs/lambda
git submodule init libs/move
git submodule init libs/mpl
git submodule init libs/optional
git submodule init libs/predef
git submodule init libs/preprocessor
git submodule init libs/smart_ptr
git submodule init libs/static_assert
git submodule init libs/throw_exception
git submodule init libs/tuple
git submodule init libs/type_index
git submodule init libs/type_traits
git submodule init libs/typeof
git submodule init libs/utility
git submodule init libs/headers tools/boost_install tools/build
git submodule update
rm -rf libs/fusion
cp -rp $TRAVIS_BUILD_DIR libs/fusion
ln -s $(pwd)/libs/fusion $TRAVIS_BUILD_DIR
./bootstrap.sh
./b2 headers

echo '==================================> SCRIPT'

./b2 -j`(nproc || sysctl -n hw.ncpu) 2> /dev/null` libs/fusion/test toolset=$TOOLSET cxxstd=$CXXSTD

fi

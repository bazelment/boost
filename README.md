This directory is populated by cloning these github repos and checking
out boost-1.58.0 tag:

```
DIRS="algorithm align asio any assert atomic bind chrono concept_check config \
container context conversion core date_time detail exception \
filesystem foreach function functional function_types fusion heap \
integer interprocess intrusive io iterator math move mpl msm \
multi_index optional parameter predef preprocessor range ratio regex \
serialization smart_ptr static_assert system thread throw_exception \
tuple type_index type_traits utility variant"

for i in $DIRS;
do
    REPO="https://github.com/boostorg/$i.git"
    echo "Deal with $REPO"
    git clone $REPO
    pushd $i
    git checkout boost-1.58.0
    popd
done

```

The version directory is populated manually:

```
mkdir -p version/include/boost
cat > version/include/boost/version.hpp

//  Boost version.hpp configuration header file  ------------------------------//

//  (C) Copyright John maddock 1999. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/config for documentation

#ifndef BOOST_VERSION_HPP
#define BOOST_VERSION_HPP

//
//  Caution: this is the only Boost header that is guaranteed
//  to change with every Boost release. Including this header
//  will cause a recompile every time a new Boost version is
//  used.
//
//  BOOST_VERSION % 100 is the patch level
//  BOOST_VERSION / 100 % 1000 is the minor version
//  BOOST_VERSION / 100000 is the major version

#define BOOST_VERSION 105801

//
//  BOOST_LIB_VERSION must be defined to be the same as BOOST_VERSION
//  but as a *string* in the form "x_y[_z]" where x is the major version
//  number, y is the minor version number, and z is the patch level if not 0.
//  This is used by <config/auto_link.hpp> to select which library version to link to.

#define BOOST_LIB_VERSION "1_58_1"

#endif

EOF
```
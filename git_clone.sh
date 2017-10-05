#!/bin/bash

# Clone the following directories from boostorg and checkout a selected tag.

DIRS="algorithm align asio any assert atomic bind chrono concept_check config \
container context conversion core date_time detail exception \
filesystem foreach function functional function_types fusion heap \
integer interprocess intrusive io iterator move mpl msm \
multi_index optional parameter predef preprocessor range ratio regex \
serialization smart_ptr static_assert system thread throw_exception \
tuple type_index type_traits utility"

for i in $DIRS;
do
    REPO="https://github.com/boostorg/$i.git"
    echo "Deal with $REPO"
    git clone $REPO
    pushd $i
    git checkout boost-1.58.0
    popd
done



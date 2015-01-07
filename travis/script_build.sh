#!/usr/bin/env bash

set -e
set -o pipefail

if [[ ${TRAVIS_OS_NAME} == "osx" ]]; then
    # Build osx project
    echo "Building osx project"
    make osx

    # Build ios project
    echo "Building ios project (simulator)"
    make ios
fi

if [[ ${TRAVIS_OS_NAME} == "linux" ]]; then
    # Build android project
    echo "Building android project"
    # testing a weird build failing issue (refer build #38)
    echo `pwd`
    ls -l
    make android
fi


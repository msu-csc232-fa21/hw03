#! /bin/bash

mkdir generator
cd generator
cmake -G "Unix Makefiles" ..
make hw03-tests

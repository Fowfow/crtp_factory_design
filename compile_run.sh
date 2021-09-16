#!/usr/bin/bash

SOURCEFILES=`find -name "*.cpp"`
INCLUDEDIR=classes
OPTIONS=-std=c++17
TARGET=main
rm -f $TARGET
g++ $SOURCEFILES -I$INCLUDEDIR $OPTIONS -o $TARGET
./$TARGET
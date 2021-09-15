#!/usr/bin/bash

SOURCEFILES=`find -name "*.cpp"`
INCLUDEDIR=classes
TARGET=main
rm -f $TARGET
g++ $SOURCEFILES -I$INCLUDEDIR -o $TARGET
./$TARGET
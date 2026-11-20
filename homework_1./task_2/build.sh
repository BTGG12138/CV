#!/usr/bin/env bash
echo "This is a bash script, this is the first line"
echo "This is the second one, it will run after the first one"
mkdir build
c++ -c -Iinclude src/subtract.cpp -o build/subtract.o
c++ -c -Iinclude src/sum.cpp -o build/sum.o
# 库的名称始终以 'lib' 开头
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o
c++ -c -Iinclude src/main.cpp -o build/main.o
c++ build/main.o build/sum.o build/subtract.o build/libipb_arithmetic.a -o build/test_ipb_arithmetic
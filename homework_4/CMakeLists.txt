cmake_minimum_required(VERSION 3.10)
project(homework_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#include(cmake/ClangFormat.cmake)
include(cmake/StaticAnalyzers.cmake)

enable_testing()
add_subdirectory(tests)
#[[
cd /home/btgg/Desktop/CV/homework_4
mkdir build && cd build
{
    echo "=== CMake 配置 ==="
    cmake .. 2>&1 | tee build_log.txt
    
    echo -e "\n=== 编译 ==="
    make -j$(nproc) 2>&1 | tee -a build_log.txt
} > build_full_log.txt 2>&1

cd /home/btgg/Desktop/CV/homework_4
clang-format -i src/main.cpp
cd build
make -j$(nproc)

find src include \( -name '*.cpp' -o -name '*.hpp' -o -name '*.h' \) \
    -exec clang-format -i -style=file {} +
]]
cmake_minimum_required(VERSION 3.10)
project(homework_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(homework_4 STATIC
    src/homework_4.cpp
)

target_include_directories(homework_4 PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

include(cmake/ClangFormat.cmake)
include(cmake/StaticAnalyzers.cmake)

enable_testing()
add_subdirectory(tests)
#[[
# 1. 进入 task_1 目录
cd /home/btgg/Desktop/CV/homework_4

# 2. 创建 build 文件夹，进去
mkdir build && cd build

# 3. 执行cmake，读取上一级的 CMakeLists.txt
cmake ..

# 4. 编译
make -j$(nproc)

cd /home/btgg/Desktop/CV/homework_4
clang-format -i src/main.cpp
cd build
make -j$(nproc)

find src include \( -name '*.cpp' -o -name '*.hpp' -o -name '*.h' \) \
    -exec clang-format -i -style=file {} +
]]
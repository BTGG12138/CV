cmake_minimum_required(VERSION 3.16)
project(task_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(task_1 src/main.cpp)
# 指定最终可执行文件输出到 bin 文件夹
set_target_properties(task_2 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

include(cmake/ClangFormat.cmake)
include(cmake/StaticAnalyzers.cmake)

#[[
# 1. 进入 task_1 目录
cd /home/btgg/Desktop/CV/homework_2./task_1

# 2. 创建 build 文件夹，进去
mkdir build && cd build

# 3. 执行cmake，读取上一级的 CMakeLists.txt
cmake ..

# 4. 编译
make -j$(nproc)

cd /home/btgg/Desktop/CV/homework_2./task_1
clang-format -i src/main.cpp
cd build
make -j$(nproc)
]]
cmake_minimum_required(VERSION 3.10)
project(homework_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(html_writer STATIC
    src/html_writer.cpp
)

target_include_directories(html_writer PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_library(image_browser STATIC
    src/image_browser.cpp
)

target_include_directories(image_browser PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(image_browser PUBLIC html_writer)

add_executable(create_image_browser
    src/main.cpp
)

target_link_libraries(create_image_browser PUBLIC image_browser)

set_target_properties(create_image_browser PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
#[[
# 1. 进入 task_1 目录
cd /home/btgg/Desktop/CV/homework_3

# 2. 创建 build 文件夹，进去
mkdir build && cd build

# 3. 执行cmake，读取上一级的 CMakeLists.txt
cmake ..

# 4. 编译
make -j$(nproc)

cd /home/btgg/Desktop/CV/homework_3
clang-format -i src/main.cpp
cd build
make -j$(nproc)
]]
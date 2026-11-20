cmake_minimum_required(VERSION 3.16)
project(task_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 库名字 ipb_arithmetic，产出 libipb_arithmetic.a
add_library(ipb_arithmetic STATIC
    src/subtract.cpp
    src/sum.cpp
)
target_include_directories(ipb_arithmetic PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(test_ipb_arithmetic
    src/main.cpp
)
target_link_libraries(test_ipb_arithmetic PUBLIC
    ipb_arithmetic
)

# install规则
install(DIRECTORY include/
  DESTINATION include
)
install(TARGETS ipb_arithmetic
  ARCHIVE DESTINATION lib
)
install(TARGETS test_ipb_arithmetic
  RUNTIME DESTINATION bin
)

cmake_minimum_required(VERSION 3.10)

project(lab1)

add_executable(main src/main.cpp src/foo.cpp)

find_package(GTest REQUIRED)


add_executable(gtests src/tests.cpp src/foo.cpp)

target_link_libraries(gtests ${GTEST_LIBRARIES}

${CMAKE_THREAD_LIBS_INIT})

enable_testing()

add_test(gtests gtests)
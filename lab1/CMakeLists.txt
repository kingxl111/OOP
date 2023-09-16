cmake_minimum_required(VERSION 3.10)

project(lab1)

add_executable(main src/main.cpp src/time_calc.cpp)

find_package(GTest REQUIRED)


add_executable(gtests tests/tests.cpp src/time_calc.cpp)

target_link_libraries(gtests ${GTEST_LIBRARIES}

${CMAKE_THREAD_LIBS_INIT})

enable_testing()

add_test(gtests gtests)
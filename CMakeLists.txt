cmake_minimum_required(VERSION 3.18)
project(TestForSpecialTechnologyCenter)

set(GTEST_DIR "lib/googletest")

add_subdirectory(${GTEST_DIR})

include_directories(${GTEST_DIR}/googletest/include)
include_directories(${GTEST_DIR}/googlemock/include)

add_executable(TestForSTC test/main.cpp
        src/byteconverter.cpp
        src/byteconverter.h
        src/examplesource.h
        src/examplesink.h
        src/sink.h
        src/source.h)

target_link_libraries(TestForSTC gtest gmock)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")

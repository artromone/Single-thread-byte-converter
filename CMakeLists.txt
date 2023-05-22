cmake_minimum_required(VERSION 3.18)
project(Test_for_Special_Technology_Center)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libs)
add_executable(Test_for_STC main.cpp sink.h source.h byteconverter.h byteconverter.cpp examplesink.h examplesource.h byteconvertertest.h)

cmake_minimum_required(VERSION 3.25)
project(cppProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(cppProject main.cpp test/test_word.cpp Word.cpp)

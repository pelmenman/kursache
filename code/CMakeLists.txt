cmake_minimum_required(VERSION 3.25)
project(cppProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(cppProject main.cpp test/word/test_word.cpp Word.cpp test/word/test_word.h Word.h Text.h Coincidence.h)

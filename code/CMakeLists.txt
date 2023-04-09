cmake_minimum_required(VERSION 3.25)
project(cppProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(cppProject
        main.cpp
        Word.h
        Word.cpp
        test/word/test_word.cpp
        test/word/test_word.h
        Levenshtein.h
        Levenshtein.cpp
        test/levenshtein/test_levenshtein.h
        test/levenshtein/test_levenshtein.cpp
        )

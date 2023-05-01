cmake_minimum_required(VERSION 3.25)
project(cppProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(cppProject
        main.cpp
        word/Word.h
        word/Word.cpp
        test/word/test_word.cpp
        test/word/test_word.h
#        Levenshtein.h
#        Levenshtein.cpp
#        test/levenshtein/test_levenshtein.h
#        test/levenshtein/test_levenshtein.cpp
        text/Text.h
        text/Text.cpp
        test/text/test_text.h
        test/text/test_text.cpp
        ENV.h
        )

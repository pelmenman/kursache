cmake_minimum_required(VERSION 3.25)
project(cppProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(cppProject main.cpp Word.cpp Text.cpp Livenshtain.cpp Coincidence.cpp)

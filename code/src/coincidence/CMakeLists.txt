add_subdirectory(algorithms)

add_library(coincidence 
        coincidence.cpp
)

target_include_directories(coincidence PUBLIC include)
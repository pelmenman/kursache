add_subdirectory(algorithms)

add_library(coincidence
        coincidence.cpp
        preprocessed_coincidence.cpp
)

target_include_directories(coincidence PUBLIC include)

target_link_libraries(coincidence algo)
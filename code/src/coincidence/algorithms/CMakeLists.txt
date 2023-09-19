add_library(algo
        algo.cpp
        predictor.cpp
        include/algo/hash.h
        constants.cpp
)

target_include_directories(algo PUBLIC include)

target_link_libraries(algo text)
add_library(algo
        algo.cpp
        predictor.cpp
        constants.cpp
        hash.cpp
)

target_include_directories(algo PUBLIC include)

target_link_libraries(algo text)
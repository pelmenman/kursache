add_library(algo
        constants.cpp
        encoders.cpp
        hash.cpp
        algo.cpp
        predictor.cpp
)

target_include_directories(algo PUBLIC include)

target_link_libraries(algo text)
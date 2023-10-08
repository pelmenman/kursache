add_library(text
        word.cpp
        text.cpp
        grouped_text.cpp
        utils.cpp
)

target_include_directories(text PUBLIC include)
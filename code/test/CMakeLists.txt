include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(project_test
        ./main.cpp
        text/word_test.cpp
        text/text_test.cpp
        algo/boyer_moore_test.cpp
        algo/knuth_morris_pratt_test.cpp
        algo/hash/hash_test.cpp
        algo/levenshtein_test.cpp
        algo/hash_mask_test.cpp
        algo/hash_eq_test.cpp
        text/grouped_text_test.cpp
        coincidence/coincidence_test.cpp
        coincidence/preprocessed_coincidence_test.cpp
)

target_link_libraries(project_test
    PRIVATE
    GTest::GTest
    text
    algo
    coincidence
)

add_test(project_gtests project_test)
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
  main.cpp
  word_test.cpp
  text_test.cpp
  algo/boyer_mur_test.cpp
  algo/knut_morris_pratt_test.cpp)

target_link_libraries(project_test
 PRIVATE
  GTest::GTest
  text
  algo
)

add_test(project_gtests project_test)
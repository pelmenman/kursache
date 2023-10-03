add_subdirectory(text)
add_subdirectory(algo)
add_subdirectory(coincidence)

add_executable(main
                main.cpp)

target_link_libraries(main coincidence)
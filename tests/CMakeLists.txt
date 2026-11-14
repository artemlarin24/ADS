create_executable_project(AllTests)

target_link_libraries(AllTests gtest gtest_main)

add_test(NAME AllTests COMMAND AllTests)

target_sources(AllTests PRIVATE
    test_bit_field.cpp
    test_set.cpp
    test_math_vector.cpp
    test_matrix.cpp
    test_mem_data.cpp
    test_triangle_matrix.cpp
    test_vector.cpp
)

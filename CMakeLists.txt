cmake_minimum_required (VERSION 3.10)
project(contest)
enable_testing ()

set (CMAKE_CXX_STANDARD 20)
if (MSVC)
    add_compile_options (/W2)
else()
    add_compile_options (-Wall -Wsign-compare -Wfloat-equal -Wshadow -Wno-unused-const-variable)
    # set(CMAKE_CXX_FLAGS_DEBUG "-fsanitize=undefined,address")
endif()

# DEBUG macro enables debug print, testdriver
add_definitions (-DDEBUG)

set (CTEST_TEST_TIMEOUT 2)

function (add_my_test target test_number)
    add_test (NAME test_${test_number}
              COMMAND ${target} ${CMAKE_SOURCE_DIR}/test/${test_number}.in
                                ${CMAKE_SOURCE_DIR}/test/${test_number}.out
                                ${CMAKE_SOURCE_DIR}/test/${test_number}.stdout
                                ${CMAKE_SOURCE_DIR}/test/${test_number}.stderr
                                )
                                set_tests_properties( test_${test_number} PROPERTIES TIMEOUT 2)

endfunction()

add_executable (main main.cpp)
target_include_directories (main PUBLIC .) # For atcoder library

add_my_test ($<TARGET_FILE:main> 1)
add_my_test ($<TARGET_FILE:main> 2)
add_my_test ($<TARGET_FILE:main> 3)
add_my_test ($<TARGET_FILE:main> 4)
add_my_test ($<TARGET_FILE:main> 5)

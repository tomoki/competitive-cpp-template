cmake_minimum_required (VERSION 3.10)
enable_testing ()

set (CMAKE_CXX_STANDARD 17)
if (MSVC)
    add_compile_options (/W2)
else()
    add_compile_options (-Wall)
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

add_my_test ($<TARGET_FILE:main> 1)
add_my_test ($<TARGET_FILE:main> 2)
add_my_test ($<TARGET_FILE:main> 3)
add_my_test ($<TARGET_FILE:main> 4)
add_my_test ($<TARGET_FILE:main> 5)


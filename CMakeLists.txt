cmake_minimum_required(VERSION 3.30)
project(KAI_Labs)

set(CMAKE_C_STANDARD 11)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g)
    add_compile_definitions(_DEBUG)
endif()

add_executable(Lab_3_1 "Semester 2/Lab_3/Lab_3_1/Lab_3_1.c" "Semester 2/Lab_3/Lab_3_1/Lab_3_1_module.c")
add_executable(Lab_3_2 "Semester 2/Lab_3/Lab_3_2/Lab_3_2.c")
add_executable(Lab_3_3 "Semester 2/Lab_3/Lab_3_3/Lab_3_3.c" "Semester 2/Lab_3/Lab_3_3/Lab_3_3_module.c")
add_executable(Lab_3_4 "Semester 2/Lab_3/Lab_3_4/Lab_3_4.c")
add_executable(Lab_3_1_test "Semester 2/Lab_3/Lab_3_1/Lab_3_1_test.cpp")

add_executable(Lab_4_1 "Semester 2/Lab_4/Lab_4_1/Lab_4_1.c")
add_executable(Lab_4_3 "Semester 2/Lab_4/Lab_4_3/Lab_4_3.c")
add_executable(Lab_4_3_test "Semester 2/Lab_4/Lab_4_3/Lab_4_3_test.cpp")

add_executable(Lab_5_1 "Semester 2/Lab_5/Lab_5_1/Lab_5_1.c" "Semester 2/Lab_5/Lab_5_1/Lab_5_1_module.c")
add_executable(Lab_5_1_test "Semester 2/Lab_5/Lab_5_1/Lab_5_1_test.cpp")
add_executable(Lab_5_2 "Semester 2/Lab_5/Lab_5_2/Lab_5_2.c")
add_executable(Lab_5_3 "Semester 2/Lab_5/Lab_5_3/Lab_5_3.c")

add_executable(PerSiK "Semester 2/PerSiK 2025.2.c")

add_executable(Temp_Shit "Semester 2/temp_shit/temp_main_shit.c")

include(FetchContent)
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG b514bdc898e2951020cbdca1304b75f5950d1f59)
FetchContent_MakeAvailable(googletest)

target_link_libraries(Lab_3_1_test GTest::gtest_main)
target_link_libraries(Lab_4_3_test GTest::gtest_main)
target_link_libraries(Lab_5_1_test GTest::gtest_main)

enable_testing()

include(GoogleTest)
gtest_discover_tests(Lab_3_1_test)
gtest_discover_tests(Lab_4_3_test)
gtest_discover_tests(Lab_5_1_test)
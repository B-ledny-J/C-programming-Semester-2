cmake_minimum_required(VERSION 3.30)
project(KAI_Labs)

set(CMAKE_C_STANDARD 11)

add_executable(Lab_3_1 "Semester 2/Lab_3/Lab_3_1/Lab_3_1.c" "Semester 2/Lab_3/Lab_3_1/Lab_3_1_module.c")
add_executable(Lab_3_2 "Semester 2/Lab_3/Lab_3_2/Lab_3_2.c")
add_executable(Lab_3_3 "Semester 2/Lab_3/Lab_3_3/Lab_3_3.c" "Semester 2/Lab_3/Lab_3_3/Lab_3_3_module.c")
add_executable(Lab_3_4 "Semester 2/Lab_3/Lab_3_4/Lab_3_4.c")
add_executable(Lab_3_1_test "Semester 2/Lab_3/Lab_3_1/Lab_3_1_test.cpp")

add_executable(Lab_4_1 "Semester 2/Lab_4/Lab_4_1/Lab_4_1.c")

add_executable(PerSiK "Semester 2/PerSiK 2025.2.c")

include(FetchContent)
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG b514bdc898e2951020cbdca1304b75f5950d1f59)
FetchContent_MakeAvailable(googletest)

target_link_libraries(Lab_3_1_test GTest::gtest_main)

enable_testing()

include(GoogleTest)
gtest_discover_tests(Lab_3_1_test)
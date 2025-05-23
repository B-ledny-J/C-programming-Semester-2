/*
* @file Lab_5_1_test.c
* @author Дарчук Г.С., 515i
* @date 19.05.2025
* @brief Лабораторна робота №5, варіант 22
*
* Функції. Застосування вказівників. Завдання 1
*/

#include <gtest/gtest.h>
extern "C" {
#include "Lab_5_1_module.c"
}

TEST(lamp_info_writeDown_success, lamp_Info_827) {

    int lamp_CRI;
    int lamp_temperature;

    EXPECT_EQ(lamp_info_writeDown(827, &lamp_CRI, &lamp_temperature), 1);
    EXPECT_EQ(lamp_CRI, 80);
    EXPECT_EQ(lamp_temperature, 2700);
}

TEST(lamp_info_writeDown_failure, lamp_Info_800) {

    int lamp_CRI;
    int lamp_temperature;

    EXPECT_EQ(lamp_info_writeDown(800, &lamp_CRI, &lamp_temperature), 0);
}

TEST(lamp_info_writeDown_failure, lamp_Info_80) {

    int lamp_CRI;
    int lamp_temperature;

    EXPECT_EQ(lamp_info_writeDown(80, &lamp_CRI, &lamp_temperature), 0);
}

TEST(lamp_info_writeDown_success, lamp_Info_930) {

    int lamp_CRI;
    int lamp_temperature;

    EXPECT_EQ(lamp_info_writeDown(930, &lamp_CRI, &lamp_temperature), 1);
    EXPECT_EQ(lamp_CRI, 90);
    EXPECT_EQ(lamp_temperature, 3000);
}

TEST(lamp_info_writeDown_failure, lamp_Info_1013) {

    int lamp_CRI;
    int lamp_temperature;

    EXPECT_EQ(lamp_info_writeDown(1013, &lamp_CRI, &lamp_temperature), 0);
}

TEST(lamp_info_writeDown_failure, lamp_Info_Negative150) {

    int lamp_CRI;
    int lamp_temperature;

    EXPECT_EQ(lamp_info_writeDown(-150, &lamp_CRI, &lamp_temperature), 0);
}
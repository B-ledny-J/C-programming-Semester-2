/*
* @file Lab_6_2_test.c
* @author Дарчук Г.С., 515i
* @date 23.05.2025
* @brief Лабораторна робота №5, варіант 22
*
* Рядки. Параметри командного рядку. Завдання 2
*/

#include <gtest/gtest.h>
extern "C" {
#include "Lab_6_2.c"
}

TEST(process_MAC_success, mac_1) {
    char mac[18] = {"01-23-45-67-89-AB"};
    EXPECT_TRUE(process_MAC(mac));
}

TEST(process_MAC_success, mac_5) {
    char mac[18] = {"3E-7A-9C-D1-4B-F0"};
    EXPECT_TRUE(process_MAC(mac));
}

TEST(process_MAC_failure, mac_2) {
    char mac[18] = {"00--1A-2B-3C-4D-5"};
    EXPECT_FALSE(process_MAC(mac));
}

TEST(process_MAC_failure, mac_3) {
    char mac[18] = {"00-1A-2B-3C-4D-5G"};
    EXPECT_FALSE(process_MAC(mac));
}

TEST(process_MAC_failure, mac_4) {
    char mac[18] = {"00-1A-2B-3C-4D-"};
    EXPECT_FALSE(process_MAC(mac));
}
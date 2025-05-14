#include <gtest/gtest.h>
extern "C" {
#include "Lab_3_1_module.c"

TEST(PositiveDigitTest, CountRepeatedDigits1) {
    int counted[10] = {0};

    count_repeated_digits(42, counted);

    EXPECT_EQ(counted[0], 0);
    EXPECT_EQ(counted[1], 0);
    EXPECT_EQ(counted[2], 1);
    EXPECT_EQ(counted[3], 0);
    EXPECT_EQ(counted[4], 1);
    EXPECT_EQ(counted[5], 0);
    EXPECT_EQ(counted[6], 0);
    EXPECT_EQ(counted[7], 0);
    EXPECT_EQ(counted[8], 0);
    EXPECT_EQ(counted[9], 0);
}
#include <gtest/gtest.h>
extern "C" {
#include "Lab_3_1_module.c"
}

TEST(PositiveDigitTest, CountRepeatedDigits) {
    int counted[10] = {0};
    
    count_repeated_digits(110474555, counted);

    EXPECT_EQ(counted[0], 1);
    EXPECT_EQ(counted[1], 2);
    EXPECT_EQ(counted[2], 0);
    EXPECT_EQ(counted[3], 0);
    EXPECT_EQ(counted[4], 2);
    EXPECT_EQ(counted[5], 3);
    EXPECT_EQ(counted[6], 0);
    EXPECT_EQ(counted[7], 1);
    EXPECT_EQ(counted[8], 0);
    EXPECT_EQ(counted[9], 0);
}

TEST(NegativeDigitTest, CountRepeatedDigits) {
    int counted[10] = {0};

    count_repeated_digits(-27735300, counted);

    EXPECT_EQ(counted[0], 2);
    EXPECT_EQ(counted[1], 0);
    EXPECT_EQ(counted[2], 1);
    EXPECT_EQ(counted[3], 2);
    EXPECT_EQ(counted[4], 0);
    EXPECT_EQ(counted[5], 1);
    EXPECT_EQ(counted[6], 0);
    EXPECT_EQ(counted[7], 2);
    EXPECT_EQ(counted[8], 0);
    EXPECT_EQ(counted[9], 0);
}
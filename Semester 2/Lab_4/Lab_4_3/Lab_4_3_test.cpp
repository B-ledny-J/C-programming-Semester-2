#include <gtest/gtest.h>
extern "C" {
#include "Lab_4_3.c"
}

TEST(automorphCheck, is_automorphic) {
    EXPECT_EQ(is_automorphic(0), 1);
    EXPECT_EQ(is_automorphic(25), 1);
    EXPECT_EQ(is_automorphic(3), 0);
    EXPECT_EQ(is_automorphic(7), 0);
}

TEST(nearAutomorphFindCheck, near_automorphic) {
    EXPECT_EQ(near_automorphic(3), 1);
    EXPECT_EQ(is_automorphic(7), 6);
}
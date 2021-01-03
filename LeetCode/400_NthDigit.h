#pragma once
#include "Common.h"

class Solution {
public:
    int findNthDigit(int n) {
        return 0;
    }
};


class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.findNthDigit(3), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findNthDigit(11), 0);
}

#pragma once
#include "Common.h"

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.countNumbersWithUniqueDigits(2), 91);
}
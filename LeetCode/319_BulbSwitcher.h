#pragma once
#include "Common.h"

class Solution
{
public:
    int bulbSwitch(int n)
    {
        return static_cast<int>(sqrt(n));
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.bulbSwitch(3), 1);
}
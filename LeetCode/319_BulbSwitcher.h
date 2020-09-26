#pragma once
#include "Common.h"

class Solution
{
public:
    int bulbSwitch(int n)
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
    EXPECT_EQ(solution.bulbSwitch(3), 1);
}
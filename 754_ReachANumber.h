#pragma once
#include "Common.h"

class Solution
{
public:
    int reachNumber(int target)
    {
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
    EXPECT_EQ(solution.reachNumber(2), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.reachNumber(3), 2);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int leastOpsExpressTarget(int x, int target)
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
    EXPECT_EQ(solution.leastOpsExpressTarget(3, 19), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.leastOpsExpressTarget(5, 501), 8);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.leastOpsExpressTarget(100, 100000000), 3);
}
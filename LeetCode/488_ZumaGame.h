#pragma once
#include "Common.h"

class Solution
{
public:
    int findMinStep(string board, string hand)
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
    EXPECT_EQ(solution.findMinStep("WRRBBW", "RB"), -1);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findMinStep("WWRRBBWW", "WRBRW"), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.findMinStep("G", "GGGGG"), 2);
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.findMinStep("RBYYBBRRB", "YRBGB"), 3);
}
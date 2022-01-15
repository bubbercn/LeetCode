#pragma once
#include "Common.h"

class Solution
{
public:
    int flipLights(int n, int presses)
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
    EXPECT_EQ(solution.flipLights(1, 2), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.flipLights(2, 1), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.flipLights(3, 1), 4);
}
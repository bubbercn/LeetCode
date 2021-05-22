#pragma once
#include "Common.h"

class Solution
{
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.canIWin(10, 11), false);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.canIWin(10, 0), true);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.canIWin(10, 1), true);
}
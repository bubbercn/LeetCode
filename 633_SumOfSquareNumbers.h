#pragma once
#include "Common.h"

class Solution
{
public:
    bool judgeSquareSum(int c)
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
    EXPECT_EQ(solution.judgeSquareSum(5), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.judgeSquareSum(2), false);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.judgeSquareSum(4), true);
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.judgeSquareSum(2), true);
}

TEST_F(LeetCodeTest, Example5)
{
    EXPECT_EQ(solution.judgeSquareSum(1), true);
}
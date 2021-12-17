#pragma once
#include "Common.h"

class Solution
{
public:
    string solveEquation(string equation)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.solveEquation("x+5-3+x=6+x-2"), "x=2");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.solveEquation("x=x"), "Infinite solutions");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.solveEquation("2x = x"), "x=0");
}
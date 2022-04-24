#pragma once
#include "Common.h"

class Solution
{
public:
    int evaluate(string_view expression)
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
    EXPECT_EQ(solution.evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))"), 14);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.evaluate("(let x 3 x 2 x)"), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.evaluate("(let x 1 y 2 x (add x y) (add x y))"), 5);
}
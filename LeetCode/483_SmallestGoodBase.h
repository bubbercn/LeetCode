#pragma once
#include "Common.h"

class Solution
{
public:
    string smallestGoodBase(string n)
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
    EXPECT_EQ(solution.smallestGoodBase("13"), "3");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.smallestGoodBase("4681"), "8");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.smallestGoodBase("1000000000000000000"), "999999999999999999");
}
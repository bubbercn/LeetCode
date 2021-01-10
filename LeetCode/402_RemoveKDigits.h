#pragma once
#include "Common.h"

class Solution
{
public:
    string removeKdigits(string num, int k)
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
    EXPECT_EQ(solution.removeKdigits("1432219", 3), "1219");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.removeKdigits("10200", 1), "200");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.removeKdigits("10", 2), "0");
}

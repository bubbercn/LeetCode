#pragma once
#include "Common.h"

class Solution
{
public:
    string makeLargestSpecial(string s)
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
    EXPECT_EQ(solution.makeLargestSpecial("11011000"), "11100100");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.makeLargestSpecial("10"), "10");
}
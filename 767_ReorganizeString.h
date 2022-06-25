#pragma once
#include "Common.h"

class Solution
{
public:
    string reorganizeString(string s)
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
    EXPECT_EQ(solution.reorganizeString("aab"), "aba");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.reorganizeString("aabb"), "");
}

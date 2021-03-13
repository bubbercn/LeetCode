#pragma once
#include "Common.h"

class Solution
{
public:
    int characterReplacement(string s, int k)
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
    EXPECT_EQ(solution.characterReplacement("ABAB", 2), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.characterReplacement("AABABBA", 1), 4);
}

#pragma once
#include "Common.h"

class Solution
{
public:
    int longestSubstring(string s, int k)
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
    EXPECT_EQ(solution.longestSubstring("aaabb", 3), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.longestSubstring("ababbc", 2), 5);
}

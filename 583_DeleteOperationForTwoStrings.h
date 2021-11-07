#pragma once
#include "Common.h"

class Solution
{
public:
    int minDistance(string_view word1, string_view word2)
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
    EXPECT_EQ(solution.minDistance("sea", "eat"), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.minDistance("leetcode", "etco"), 4);
}
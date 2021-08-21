#pragma once
#include "Common.h"

class Solution
{
public:
    int longestPalindromeSubseq(string s)
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
    EXPECT_EQ(solution.longestPalindromeSubseq("bbbab"), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.longestPalindromeSubseq("cbbd"), 2);
}
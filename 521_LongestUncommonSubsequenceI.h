#pragma once
#include "Common.h"

class Solution
{
public:
    int findLUSlength(string_view a, string_view b)
    {
        if (a == b)
            return -1;
        return max(a.length(), b.length()); 
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.findLUSlength("aba", "cdc"), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findLUSlength("aaa", "bbb"), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.findLUSlength("aaa", "aaa"), -1);
}
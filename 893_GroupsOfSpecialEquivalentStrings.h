#pragma once
#include "Common.h"

class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &words)
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
    vector<string> words = {"abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx"};
    EXPECT_EQ(solution.numSpecialEquivGroups(words), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"abc", "acb", "bac", "bca", "cab", "cba"};
    EXPECT_EQ(solution.numSpecialEquivGroups(words), 3);
}

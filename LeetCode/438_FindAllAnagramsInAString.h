#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
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
    vector<int> output = {0, 6};
    EXPECT_EQ(solution.findAnagrams("cbaebabacd", "abc"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {0, 1, 2};
    EXPECT_EQ(solution.findAnagrams("abab", "ab"), output);
}
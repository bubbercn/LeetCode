#pragma once
#include "Common.h"

class Solution
{
public:
    string shortestSuperstring(vector<string> &words)
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
    vector<string> words = {"alex", "loves", "leetcode"};
    EXPECT_EQ(solution.shortestSuperstring(words), "alexlovesleetcode");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"catg", "ctaagt", "gcta", "ttca", "atgcatc"};
    EXPECT_EQ(solution.shortestSuperstring(words), "gctaagttcatgcatc");
}
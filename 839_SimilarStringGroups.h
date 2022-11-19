#pragma once
#include "Common.h"

class Solution
{
public:
    int numSimilarGroups(vector<string> &strs)
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
    vector<string> strs = {"tars", "rats", "arts", "star"};
    EXPECT_EQ(solution.numSimilarGroups(strs), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> strs = {"omv", "ovm"};
    EXPECT_EQ(solution.numSimilarGroups(strs), 1);
}
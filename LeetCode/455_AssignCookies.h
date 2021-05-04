#pragma once
#include "Common.h"

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
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
    vector<int> g = {1, 2, 3}, s = {1, 1};
    EXPECT_EQ(solution.findContentChildren(g, s), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> g = {1, 2}, s = {1, 2, 3};
    EXPECT_EQ(solution.findContentChildren(g, s), 2);
}

#pragma once
#include "Common.h"

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
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
    vector<int> profits = {1, 2, 3}, capital = {0, 1, 1};
    EXPECT_EQ(solution.findMaximizedCapital(2, 0, profits, capital), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> profits = {1, 2, 3}, capital = {0, 1, 2};
    EXPECT_EQ(solution.findMaximizedCapital(3, 0, profits, capital), 6);
}

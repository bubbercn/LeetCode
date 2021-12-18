#pragma once
#include "Common.h"

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
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
    vector<vector<int>> pairs = {
        {1, 2},
        {2, 3},
        {3, 4},
    };
    EXPECT_EQ(solution.findLongestChain(pairs), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> pairs = {
        {1, 2},
        {7, 8},
        {4, 5},
    };
    EXPECT_EQ(solution.findLongestChain(pairs), 3);
}
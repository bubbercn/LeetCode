#pragma once
#include "Common.h"

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
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
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1},
    };
    EXPECT_EQ(solution.findCircleNum(isConnected), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> isConnected = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
    };
    EXPECT_EQ(solution.findCircleNum(isConnected), 3);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
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
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1},
    };
    EXPECT_EQ(solution.networkDelayTime(times, 4, 2), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> times = {
        {1, 2, 1},
    };
    EXPECT_EQ(solution.networkDelayTime(times, 2, 1), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> times = {
        {1, 2, 1},
    };
    EXPECT_EQ(solution.networkDelayTime(times, 2, 2), -1);
}
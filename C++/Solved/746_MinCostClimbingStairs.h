#pragma once
#include "Common.h"

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> result(n + 1, 0);
        for (int i = 2; i < result.size(); i++)
        {
            result[i] = min(cost[i - 1] + result[i - 1], cost[i - 2] + result[i - 2]);
        }
        return result[n];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> cost = {10, 15, 20};
    EXPECT_EQ(solution.minCostClimbingStairs(cost), 15);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    EXPECT_EQ(solution.minCostClimbingStairs(cost), 6);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        int dpNoStock = 0;
        int dpStock = -prices[0];
        for (int i = 1; i < n; i++)
        {
            int temp = max(dpNoStock, dpStock + prices[i] - fee);
            dpStock = max(dpStock, dpNoStock - prices[i]);
            dpNoStock = temp;
        }
        return dpNoStock;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    EXPECT_EQ(solution.maxProfit(prices, 2), 8);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> prices = {1, 3, 7, 5, 10, 3};
    EXPECT_EQ(solution.maxProfit(prices, 3), 6);
}
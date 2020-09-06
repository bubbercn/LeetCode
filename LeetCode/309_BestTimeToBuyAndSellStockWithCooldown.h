#pragma once
#include "Common.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;

        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        for (size_t i = 0; i < prices.size(); i++)
        {
            if (i == 0)
            {
                dp[0][0] = 0;
                dp[0][1] = -prices[0];
            }
            else if (i == 1)
            {
                dp[1][0] = max(0, prices[1] - prices[0]);
                dp[1][1] = max(-prices[0], -prices[1]);
            }
            else
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
            }
        }
        return dp[prices.size() - 1][0];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> prices = {1, 2, 3, 0, 2};
    EXPECT_EQ(solution.maxProfit(prices), 3);
}
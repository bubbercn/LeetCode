#pragma once
#include "Common.h"

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int N = prices.size();
        if (N == 0)
            return 0;

        if (k > N / 2)
            return maxProfit(prices);

        vector<vector<int>> dp(k + 1, vector<int>(2));
        for (int i = 0; i < N; i++)
        {
            for (int j = k; j >= 0; j--)
            {
                if (i == 0 && j == 0)
                {
                    dp[0][0] = 0;
                    dp[0][1] = INT_MIN;
                }
                else if (j == 0)
                {
                    dp[0][0] = dp[0][0];
                    dp[0][1] = INT_MIN;
                }
                else if (i == 0)
                {
                    dp[j][0] = 0;
                    dp[j][1] = -prices[0];
                }
                else
                {
                    dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
                    dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]);
                }
            }
        }
        return dp[k][0];
    }

private:
    int maxProfit(vector<int> &prices)
    {
        int currentProfit = 0;
        int totalProfit = 0;
        int buy = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (i == 0)
            {
                buy = prices[0];
            }
            else if (prices[i] < prices[i - 1])
            {
                totalProfit += currentProfit;
                buy = prices[i];
                currentProfit = 0;
            }
            else
            {
                currentProfit = max(currentProfit, prices[i] - buy);
            }
        }
        totalProfit += currentProfit;
        return totalProfit;
    }
};

void Test()
{
    Solution solution;
    vector<int> prices;
    int k;

    prices = {2, 4, 1};
    k = 2;
    assert(solution.maxProfit(k, prices) == 2);

    prices = {3, 2, 6, 5, 0, 3};
    k = 2;
    assert(solution.maxProfit(k, prices) == 7);
}
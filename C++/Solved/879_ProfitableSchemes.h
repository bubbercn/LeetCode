#pragma once
#include "Common.h"

class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        int c = group.size();
        vector<vector<vector<int>>> dp(c + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= c; i++)
        {
            int cost = group[i - 1];
            int p = profit[i - 1];
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k <= minProfit; k++)
                {
                    if (j < cost)
                    {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                    else
                    {
                        dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j - cost][max(0, k - p)]) % MOD;
                    }
                }
            }
        }
        int result = 0;
        for (int j = 0; j <= n; j++)
        {
            result += dp[c][j][minProfit];
            result %= MOD;
        }
        return result;
    }

private:
    static constexpr int MOD = 1000000000 + 7;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> group = {2, 2};
    vector<int> profit = {2, 3};
    EXPECT_EQ(solution.profitableSchemes(5, 3, group, profit), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> group = {2, 3, 5};
    vector<int> profit = {6, 7, 8};
    EXPECT_EQ(solution.profitableSchemes(10, 5, group, profit), 7);
}
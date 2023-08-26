#pragma once
#include "Common.h"

class Solution
{
public:
    int kInversePairs(int n, int k)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = 1;
                }
                else if (j > i * (i - 1) / 2)
                {
                    dp[i][j] = 0;
                }
                else if (j <= i - 1)
                {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                    dp[i][j] %= MOD;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                    dp[i][j] %= MOD;
                    dp[i][j] -= dp[i - 1][j - i];
                    if (dp[i][j] < 0)
                        dp[i][j] += MOD;
                }
            }
        }
        return dp[n][k];
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
    EXPECT_EQ(solution.kInversePairs(3, 0), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.kInversePairs(3, 1), 2);
}
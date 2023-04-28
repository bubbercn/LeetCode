#pragma once
#include "Common.h"

class Solution
{
public:
    int numMusicPlaylists(int n, int goal, int k)
    {
        // vector<vector<long>> dp(goal + 1, vector<long>(n + 1));
        // dp[0][0] = 1;
        // for (int i = 1; i <= goal; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         dp[i][j] = (dp[i - 1][j - 1] * (n - j + 1) + dp[i - 1][j] * max(j - k, 0)) % MOD;
        //     }
        // }
        // return dp[goal][n];
        // vector<vector<long>> dp(n + 1, vector<long>(goal + 1));
        // dp[0][0] = 1;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= goal; j++)
        //     {
        //         dp[i][j] = (dp[i - 1][j - 1] * (n - i + 1) + dp[i][j - 1] * max(i - k, 0)) % MOD;
        //     }
        // }
        // return dp[n][goal];
        vector<vector<long>> dp(2, vector<long>(goal + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= goal; j++)
            {
                dp[1][j] = (dp[0][j - 1] * (n - i + 1) + dp[1][j - 1] * max(i - k, 0)) % MOD;
            }
            swap(dp[0], dp[1]);
            dp[1].assign(goal + 1, 0);
        }
        return dp[0][goal];
    }

private:
    static constexpr int MOD = 1000000007;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.numMusicPlaylists(3, 3, 1), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.numMusicPlaylists(2, 3, 0), 6);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.numMusicPlaylists(2, 3, 1), 2);
}
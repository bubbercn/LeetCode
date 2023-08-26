#pragma once
#include "Common.h"

class Solution
{
public:
    int tallestBillboard(vector<int> &rods)
    {
        int m = rods.size();
        int n = accumulate(rods.begin(), rods.end(), 0);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, numeric_limits<int>::min()));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++)
        {
            int rod = rods[i - 1];
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j + rod < n)
                {
                    dp[i][j + rod] = max(dp[i][j + rod], dp[i - 1][j]);
                }
                if (j >= rod)
                {
                    dp[i][j - rod] = max(dp[i][j - rod], dp[i - 1][j] + rod);
                }
                else
                {
                    dp[i][rod - j] = max(dp[i][rod - j], dp[i - 1][j] + j);
                }
            }
        }
        return dp[m][0];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> rods = {1, 2, 3, 6};
    EXPECT_EQ(solution.tallestBillboard(rods), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> rods = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(solution.tallestBillboard(rods), 10);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> rods = {1, 2};
    EXPECT_EQ(solution.tallestBillboard(rods), 0);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> rods = {100};
    EXPECT_EQ(solution.tallestBillboard(rods), 0);
}
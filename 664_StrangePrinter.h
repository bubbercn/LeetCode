#pragma once
#include "Common.h"

class Solution
{
public:
    int strangePrinter(string_view s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for (int k = 1; k < n; k++)
        {
            for (int i = 0, j = k; i < n - k; i++, j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + dp[i + 1][j];
                    for (int l = i + 1; l < j; l++)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][l] + dp[l + 1][j]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.strangePrinter("aaabbb"), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.strangePrinter("aba"), 2);
}
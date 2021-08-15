#pragma once
#include "Common.h"

class Solution
{
public:
    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int k = 1; k < n; k++)
        {
            for (int l = 1; l <= n - k; l++)
            {
                int temp = INT_MAX;
                for (int i = l; i < l + k; i++)
                {
                    temp = min(temp, i + max(dp[l][i - 1], dp[i + 1][l + k]));
                }
                dp[l][l + k] = temp;
            }
        }

        return dp[1][n];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.getMoneyAmount(10), 16);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.getMoneyAmount(1), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.getMoneyAmount(2), 1);
}

TEST_F(LeetCodeTest, n5)
{
    EXPECT_EQ(solution.getMoneyAmount(5), 6);
}
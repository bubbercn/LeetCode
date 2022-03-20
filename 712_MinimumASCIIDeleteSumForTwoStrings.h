#pragma once
#include "Common.h"

class Solution
{
public:
    int minimumDeleteSum(string_view s1, string_view s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i <= n1; i++)
        {
            for (int j = 0; j <= n2; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (i == 0)
                {
                    dp[i][j] = s2[j - 1];
                }
                else if (j == 0)
                {
                    dp[i][j] = s1[i - 1];
                }
                else
                {
                    if (s1[i - 1] == s2[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = min(dp[i - 1][j - 1] + s1[i - 1] + s2[j - 1], dp[i - 1][j] + s1[i - 1]);
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + s2[j - 1]);
                    }
                }
            }
        }
        return dp[n1][n2];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.minimumDeleteSum("sea", "eat"), 231);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.minimumDeleteSum("delete", "leet"), 403);
}

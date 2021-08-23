#pragma once
#include "Common.h"

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                if (i == 0)
                {
                    dp[j][i + j] = 1;
                }
                else if (s[j] == s[i + j])
                {
                    dp[j][i + j] = dp[j + 1][i + j - 1] + 2;
                }
                else
                {
                    dp[j][i + j] = max(dp[j + 1][i + j], dp[j][i + j - 1]);
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
    EXPECT_EQ(solution.longestPalindromeSubseq("bbbab"), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.longestPalindromeSubseq("cbbd"), 2);
}
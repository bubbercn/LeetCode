#pragma once
#include "Common.h"

class Solution
{
public:
    int countPalindromicSubsequences(string_view s)
    {
        int n = s.length();
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(n, vector<int>(n, 0)));
        for (int l = 0; l < n; l++)
        {
            for (int i = 0, j = i + l; i < n && j < n; i++, j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    char c = 'a' + k;
                    if (i == j)
                    {
                        if (s[i] == c)
                        {
                            dp[k][i][j] = 1;
                        }
                        else
                        {
                            dp[k][i][j] = 0;
                        }
                    }
                    else
                    {
                        if (s[i] != c)
                        {
                            dp[k][i][j] = dp[k][i + 1][j];
                        }
                        else if (s[j] != c)
                        {
                            dp[k][i][j] = dp[k][i][j - 1];
                        }
                        else
                        {
                            int &sum = dp[k][i][j];
                            sum = 2;
                            for (int k = 0; k < 4; k++)
                            {
                                sum += dp[k][i + 1][j - 1];
                                sum %= MOD;
                            }
                        }
                    }
                }
            }
        }
        int result = 0;
        for (int k = 0; k < 4; k++)
        {
            result += dp[k][0][n - 1];
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
    EXPECT_EQ(solution.countPalindromicSubsequences("bccb"), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.countPalindromicSubsequences("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"), 104860361);
}
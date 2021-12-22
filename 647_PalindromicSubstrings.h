#pragma once
#include "Common.h"

class Solution
{
public:
    int countSubstrings(string_view s)
    {
        int result = 0;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int k = 0; k < n; k++)
        {
            for (int i = 0, j = k; i < n - k; i++, j++)
            {
                if (i == j)
                {
                    dp[i][j] = true;
                }
                else if (s[i] == s[j])
                {
                    if (i + 1 == j)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j])
                    result++;
            }
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.countSubstrings("abc"), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.countSubstrings("aaa"), 6);
}
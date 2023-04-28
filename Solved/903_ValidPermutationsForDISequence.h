#pragma once
#include "Common.h"

class Solution
{
public:
    int numPermsDISequence(string_view s)
    {
        int n = s.length() + 1;
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == 'D')
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % MOD;
                }
            }
            else
            {
                for (int j = 1; j <= i; j++)
                {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result = (result + dp[n - 1][i]) % MOD;
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
    EXPECT_EQ(solution.numPermsDISequence("DID"), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.numPermsDISequence("D"), 1);
}
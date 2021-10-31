#pragma once
#include "Common.h"

class Solution
{
public:
    int checkRecord(int n)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                dp[0][0][0] = 1;
                dp[0][0][1] = 1;
                dp[0][1][0] = 1;
            }
            else
            {
                // P
                for (int j = 0; j < 2; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        dp[i][j][0] += dp[i - 1][j][k];
                        dp[i][j][0] %= m;
                    }
                }

                // A
                for (int k = 0; k < 3; k++)
                {
                    dp[i][1][0] += dp[i - 1][0][k];
                    dp[i][1][0] %= m;
                }

                // L
                for (int j = 0; j < 2; j++)
                {
                    for (int k = 1; k < 3; k++)
                    {
                        dp[i][j][k] += dp[i - 1][j][k - 1];
                        dp[i][j][k] %= m;
                    }
                }
            }
        }
        int result = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                result += dp[n - 1][i][j];
                result %= m;
            }
        }
        return result;
    }

private:
    static constexpr int m = 1000000000 + 7;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.checkRecord(2), 8);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.checkRecord(1), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.checkRecord(10101), 183236316);
}
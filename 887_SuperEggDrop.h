#pragma once
#include "Common.h"

class Solution
{
public:
    int superEggDrop(int k, int n)
    {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, numeric_limits<int>::max()));
        for (int i = 0; i <= k; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= n; i++)        
        {
            dp[1][i] = i;
        }

        for (int i = 2; i <= k; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int min = numeric_limits<int>::max();
                int left = 1;
                int right = j;
                while (left <= right)
                {
                    int middle = (left + right) / 2;
                    int broken = dp[i - 1][middle - 1];
                    int notBroken = dp[i][j - middle];
                    if (broken > notBroken)
                    {
                        right = middle - 1;
                        min = ::min(min, broken + 1);
                    }
                    else
                    {
                        left = middle + 1;
                        min = ::min(min, notBroken + 1);
                    }
                }
                // for (int x = 1; x <= j; x++)
                // {
                //     int temp = max(dp[i - 1][x - 1], dp[i][j - x]);
                //     min = ::min(temp + 1, min);
                // }
                dp[i][j] = min;
            }
        }

        return dp[k][n];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.superEggDrop(1, 2), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.superEggDrop(2, 6), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.superEggDrop(3, 14), 4);
}

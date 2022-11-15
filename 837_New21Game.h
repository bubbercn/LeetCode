#pragma once
#include "Common.h"

class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (n - k + 1 >= maxPts)
            return 1;

        vector<double> dp(k + maxPts);
        for (int i = k; i <= n; i++)
        {
            dp[i] = 1.0;
        }
        double sumProb = n - k + 1;
        for (int i = k - 1; i >= 0; i--)
        {
            dp[i] = sumProb / maxPts;
            sumProb = sumProb - dp[i + maxPts] + dp[i];
        }

        return dp[0];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.new21Game(10, 1, 10), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.new21Game(6, 1, 10), 0.6);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.new21Game(21, 17, 10), 0.73278);
}

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.new21Game(10, 2, 10), 0.99);
}
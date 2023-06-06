#pragma once
#include "Common.h"

class Solution
{
public:
    int leastOpsExpressTarget(int x, int target)
    {
        int a = x;
        int b = 1;
        int t = 0;
        while (a - b <= target)
        {
            a *= x;
            b *= x;
            t++;
        }
        vector<int> dp(b);
        dp[0] = -1;
        for (int i = 1; i < dp.size(); i++)
        {
            dp[i] = dp[i - 1] + 2;
        }
        int cost = 1;
        int gain = x;
        while (gain <= b)
        {
            for (int i = gain; i < dp.size(); i++)
            {
                dp[i] = min(dp[i], dp[i - gain] + cost);
            }
            gain *= x;
            cost += 1;
        }
        for (int i = dp.size() - 3; i >= 1; i--)
        {
            dp[i] = min(dp[i], dp[i + 1] + 2);
        }
        cost = 1;
        gain = x;
        while (gain < b)
        {
            for (int i = dp.size() - 1 - gain; i >= 1; i--)
            {
                dp[i] = min(dp[i], dp[i + gain] + cost);
            }
            gain *= x;
            cost += 1;
        }
        return dp[target];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.leastOpsExpressTarget(3, 19), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.leastOpsExpressTarget(5, 501), 8);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.leastOpsExpressTarget(100, 100000000), 3);
}
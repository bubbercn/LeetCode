#pragma once
#include "Common.h"

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int m = days.size();
        int n = costs.size();
        vector<int> dp(m, INT_MAX);
        for (int i = 0; i < m; i++)
        {
            if (i == 0)
            {
                dp[i] = min(costs[0], min(costs[1], costs[2]));
            }
            else
            {
                dp[i] = dp[i - 1] + costs[0];
                bool found = false;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (days[i] - days[j] >= 7)
                    {
                        dp[i] = min(dp[i], dp[j] + costs[1]);
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    dp[i] = min(dp[i], costs[1]);
                }
                found = false;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (days[i] - days[j] >= 30)
                    {
                        dp[i] = min(dp[i], dp[j] + costs[2]);
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    dp[i] = min(dp[i], costs[2]);
                }
            }
        }
        return dp[m - 1];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    EXPECT_EQ(solution.mincostTickets(days, costs), 11);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> costs = {2, 7, 15};
    EXPECT_EQ(solution.mincostTickets(days, costs), 17);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {7, 2, 15};
    EXPECT_EQ(solution.mincostTickets(days, costs), 6);
}

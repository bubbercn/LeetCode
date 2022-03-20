#pragma once
#include "Common.h"

class Solution
{
public:
    int minimumDeleteSum(string_view s1, string_view s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<int> dp(n2 + 1, 0);
        int p = 0;
        for (int i = 0; i <= n1; i++)
        {
            for (int j = 0; j <= n2; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[j] = 0;
                }
                else if (i == 0)
                {
                    dp[j] = dp[j - 1] + s2[j - 1];
                }
                else if (j == 0)
                {
                    p = dp[j];
                    dp[j] += s1[i - 1];
                }
                else
                {
                    if (s1[i - 1] == s2[j - 1])
                    {
                        swap(p, dp[j]);
                    }
                    else
                    {
                        p = dp[j];
                        dp[j] = min(dp[j - 1] + s2[j - 1], dp[j] + s1[i - 1]);
                    }
                }
            }
        }
        return dp[n2];
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

#pragma once
#include "Common.h"

class Solution
{
public:
    int minDistance(string_view word1, string_view word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= m; i++)
        {
            int pre = 0;
            for (int j = 0; j <= n; j++)
            {
                if (i == 0)
                {
                    dp[j] = j;
                }
                else if (j == 0)
                {
                    pre = dp[j];
                    dp[j] = i;
                }
                else
                {
                    int temp = dp[j];
                    if (word1[i - 1] == word2[j - 1])
                    {
                        dp[j] = pre;
                    }
                    else
                    {
                        dp[j] = min(dp[j], dp[j - 1]) + 1;
                    }
                    pre = temp;
                }
            }
        }
        return dp[n];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.minDistance("sea", "eat"), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.minDistance("leetcode", "etco"), 4);
}

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.minDistance("a", "b"), 2);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.minDistance("sea", "ate"), 4);
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.minDistance("mart", "karma"), 5);
}

TEST_F(LeetCodeTest, Failure3)
{
    EXPECT_EQ(solution.minDistance("intention", "execution"), 8);
}
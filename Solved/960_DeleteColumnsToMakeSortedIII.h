#pragma once
#include "Common.h"

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int m = strs.size();
        int n = strs[0].length();
        vector<int> dp(n, 1);
        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k < j; k++)
            {
                bool ok = true;
                for (int i = 0; i < m; i++)
                {
                    if (strs[i][k] > strs[i][j])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    dp[j] = max(dp[j], dp[k] + 1);
                }
            }
        }
        return n - *max_element(dp.begin(), dp.end());
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> strs = {"babca", "bbazb"};
    EXPECT_EQ(solution.minDeletionSize(strs), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> strs = {"edcba"};
    EXPECT_EQ(solution.minDeletionSize(strs), 4);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> strs = {"ghi", "def", "abc"};
    EXPECT_EQ(solution.minDeletionSize(strs), 0);
}

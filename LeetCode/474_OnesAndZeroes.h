#pragma once
#include "Common.h"

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < strs.size(); i++)
        {
            auto [numOf0, numOf1] = calWeight(strs[i]);
            for (int j = m; j >= 0 ; j--)
            {
                for (int k = n; k >= 0; k--)
                {
                    dp[j][k] = (i == 0 ? 0 : dp[j][k]);
                    if (j >= numOf0 && k >= numOf1)
                    {
                        dp[j][k] = max(dp[j][k], (i == 0 ? 0 : dp[j - numOf0][k - numOf1]) + 1);
                    }
                }
            }
        }
        return dp[m][n];
    }

private:
    pair<int, int> calWeight(const string &input)
    {
        int numOf0 = 0, numOf1 = 0;
        for (auto c : input)
        {
            if (c == '0')
            {
                numOf0++;
            }
            else
            {
                numOf1++;
            }
        }
        return {numOf0, numOf1};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    EXPECT_EQ(solution.findMaxForm(strs, 5, 3), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> strs = {"10", "0", "1"};
    EXPECT_EQ(solution.findMaxForm(strs, 1, 1), 2);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    EXPECT_EQ(solution.findMaxForm(strs, 3, 4), 3);
}
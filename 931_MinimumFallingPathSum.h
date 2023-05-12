#pragma once
#include "Common.h"

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> dp = matrix[0];
        for (int i = 1; i < n; i++)
        {
            vector<int> next(n);
            for (int j = 0; j < n; j++)
            {
                int temp = dp[j];
                if (j > 0)
                    temp = min(temp, dp[j - 1]);
                if (j < n - 1)
                    temp = min(temp, dp[j + 1]);
                next[j] = temp + matrix[i][j];
            }
            dp.swap(next);
        }
        return *min_element(dp.begin(), dp.end());
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9},
    };
    EXPECT_EQ(solution.minFallingPathSum(matrix), 13);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> matrix = {
        {-19, 57},
        {-40, -5},
    };
    EXPECT_EQ(solution.minFallingPathSum(matrix), -59);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int removeBoxes(vector<int> &boxes)
    {
        dp.assign(100, vector<vector<int>>(100, vector<int>(100, 0)));
        return helper(boxes, 0, boxes.size() - 1, 0);
    }

    int helper(vector<int> &boxes, int l, int r, int k)
    {
        if (l > r)
        {
            return 0;
        }
        if (dp[l][r][k] == 0)
        {
            dp[l][r][k] = helper(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
            for (int i = l; i < r; i++)
            {
                if (boxes[i] == boxes[r])
                {
                    dp[l][r][k] = max(dp[l][r][k], helper(boxes, l, i, k + 1) + helper(boxes, i + 1, r - 1, 0));
                }
            }
        }
        return dp[l][r][k];
    }

private:
    vector<vector<vector<int>>> dp;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    EXPECT_EQ(solution.removeBoxes(boxes), 23);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> boxes = {1, 1, 1};
    EXPECT_EQ(solution.removeBoxes(boxes), 9);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> boxes = {1};
    EXPECT_EQ(solution.removeBoxes(boxes), 1);
}
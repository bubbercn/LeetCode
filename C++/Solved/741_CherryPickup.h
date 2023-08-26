#pragma once
#include "Common.h"

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int limit = n * 2 - 1;
        for (int k = 0; k < limit; k++)
        {
            vector<vector<int>> dpNext(n, vector<int>(n, 0));
            for (int x1 = 0; x1 < n; x1++)
            {
                int y1 = k - x1;
                if (y1 < 0)
                    break;
                if (y1 >= n)
                    continue;
                for (int x2 = x; x2 < n; x2++)
                {
                    int y2 = k - x2;
                    if (y2 < 0)
                        break;
                    if (y2 >= n)
                        continue;

                    if (k == 0)
                    {
                        dpNext[0][0] = grid[0][0];
                    }
                    else if (grid[x1][y1] == -1 || grid[x2][y2] == -1)
                    {
                        dpNext[x1][x2] = numeric_limits<int>::min();
                    }
                    else
                    {
                        int pre = numeric_limits<int>::min();
                        if (k - 1 - x1 >= 0 && k - 1 - x2 >= 0)
                        {
                            pre = max(pre, dp[x1][x2]);
                        }
                        if (x1 - 1 >= 0 && x2 - 1 >= 0)
                        {
                            pre = max(pre, dp[x1 - 1][x2 - 1]);
                        }
                        if (k - 1 - x1 >= 0 && x2 - 1 >= 0)
                        {
                            pre = max(pre, dp[x1][x2 - 1]);
                        }
                        if (x1 - 1 >= 0 && k - 1 - x2 >= 0)
                        {
                            pre = max(pre, dp[x1 - 1][x2]);
                        }
                        if (pre == numeric_limits<int>::min())
                        {
                            dpNext[x1][x2] = pre;
                        }
                        else
                        {
                            int cherry = x1 == x2 ? grid[x1][y1] : grid[x1][y1] + grid[x2][y2];
                            dpNext[x1][x2] = cherry + pre;
                        }
                    }
                }
            }
            dp.swap(dpNext);
        }
        return dp[n - 1][n - 1] == numeric_limits<int>::min() ? 0 : dp[n - 1][n - 1];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> grid = {
        {0, 1, -1},
        {1, 0, -1},
        {1, 1, 1},
    };
    EXPECT_EQ(solution.cherryPickup(grid), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {1, 1, -1},
        {1, -1, 1},
        {-1, 1, 1},
    };
    EXPECT_EQ(solution.cherryPickup(grid), 0);
}

TEST_F(LeetCodeTest, Case1)
{
    vector<vector<int>> grid = {
        {1, 1, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 1, 1},
    };
    EXPECT_EQ(solution.cherryPickup(grid), 11);
}
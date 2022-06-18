#pragma once
#include "Common.h"

class Solution
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
    {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for (auto &mine : mines)
        {
            grid[mine[0]][mine[1]] = 0;
        }
        vector<vector<int>> state(n, vector<int>(n, numeric_limits<int>::max()));
        int sum = 0;
        auto update = [&](int i, int j)
        {
            if (grid[i][j] == 0)
            {
                sum = 0;
            }
            else
            {
                sum++;
            }
            state[i][j] = min(state[i][j], sum);
        };
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                update(i, j);
            }
            sum = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                update(i, j);
            }
        }
        for (int j = 0; j < n; j++)
        {
            sum = 0;
            for (int i = 0; i < n; i++)
            {
                update(i, j);
            }
            sum = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                update(i, j);
            }
        }
        vector<int> maxRow;
        for (auto &row : state)
        {
            maxRow.emplace_back(*max_element(row.begin(), row.end()));
        }
        return *max_element(maxRow.begin(), maxRow.end());
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> mines = {{4, 2}};
    EXPECT_EQ(solution.orderOfLargestPlusSign(5, mines), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> mines = {{0, 0}};
    EXPECT_EQ(solution.orderOfLargestPlusSign(1, mines), 0);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> mines = {{0, 0}, {0, 1}, {0, 4}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {3, 0}, {4, 0}, {4, 1}, {4, 3}, {4, 4}};
    EXPECT_EQ(solution.orderOfLargestPlusSign(5, mines), 1);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<vector<int>> mines = {{3, 0}, {3, 3}};
    EXPECT_EQ(solution.orderOfLargestPlusSign(5, mines), 3);
}
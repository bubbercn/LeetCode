#pragma once
#include "Common.h"

class Solution
{
public:
    double knightProbability(int n, int k, int row, int column)
    {
        PositionSet current = {{row, column}};
        double totalCount = pow(8, k);
        lookup.assign(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        double onCount = helper(row, column, n, k);
        return onCount / totalCount;
    }

private:
    using PositionSet = set<pair<int, int>>;
    double helper(int x, int y, int n, int k)
    {
        const static vector<pair<int, int>> moves = {
            {-2, 1},
            {-1, 2},
            {1, 2},
            {2, 1},
            {2, -1},
            {1, -2},
            {-1, -2},
            {-2, -1},
        };

        if (x < 0 || x >= n || y < 0 || y >=n)
        {
            return 0;
        }

        if (k == 0)
            return 1;
        
        if (lookup[x][y][k] != -1)
            return lookup[x][y][k];

        double result = 0;

        for (auto [dx, dy] : moves)
        {
            int next_x = x + dx;
            int next_y = y + dy;
            result += helper(next_x, next_y, n, k - 1);
        }
        lookup[x][y][k] = result;
        return result;
    }
    vector<vector<vector<double>>> lookup;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.knightProbability(3, 2, 0, 0), 0.06250);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.knightProbability(1, 0, 0, 0), 1);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.knightProbability(3, 2, 1, 1), 0);
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(static_cast<int>(solution.knightProbability(8, 30, 6, 4) * 100000), static_cast<int>(0.00019 * 100000));
}
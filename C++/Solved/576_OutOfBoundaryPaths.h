#pragma once
#include "Common.h"

class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        int result = 0;
        vector<vector<int>> current(m, vector<int>(n, 0));
        current[startRow][startColumn] = 1;
        for (int move = 0; move < maxMove; move++)
        {
            vector<vector<int>> next(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int count = current[i][j];
                    for (auto [dx, dy] : directions)
                    {
                        int x = i + dx;
                        int y = j + dy;
                        if (x >= 0 && x < m && y >= 0 && y < n)
                        {
                            next[x][y] += count;
                            next[x][y] %= mod;
                        }
                        else
                        {
                            result += count;
                            result %= mod;
                        }
                    }
                }
            }
            current.swap(next);
        }
        return result;
    }

private:
    inline static vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    static constexpr int mod = 1000000000 + 7;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.findPaths(2, 2, 2, 0, 0), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findPaths(1, 3, 3, 0, 1), 12);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.findPaths(1, 2, 50, 0, 0), 150);
}
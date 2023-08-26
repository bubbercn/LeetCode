#pragma once
#include "Common.h"

class Solution
{
public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int x = 0;
        int y = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == 'R')
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        int result = 0;
        for (auto [dx, dy] : directions)
        {
            int tx = x;
            int ty = y;
            while (true)
            {
                tx += dx;
                ty += dy;
                if (tx < 0 or tx >= 8 or ty < 0 || ty >= 8)
                    break;

                if (board[tx][ty] == 'B')
                    break;

                if (board[tx][ty] == 'p')
                {
                    result++;
                    break;
                }
            }
        }
        return result;
    }

private:
    inline static vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<char>> board = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'.', '.', '.', 'R', '.', '.', '.', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
    };
    EXPECT_EQ(solution.numRookCaptures(board), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<char>> board = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
        {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
        {'.', 'p', 'B', 'R', 'B', 'p', '.', '.'},
        {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
        {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
    };
    EXPECT_EQ(solution.numRookCaptures(board), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<char>> board = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'p', 'p', '.', 'R', '.', 'p', 'B', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
    };
    EXPECT_EQ(solution.numRookCaptures(board), 3);
}
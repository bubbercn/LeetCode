#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int x = click[0];
        int y = click[1];
        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
        }
        else
        {
            dfs(board, x, y);
        }
        return board;
    }

private:
    void dfs(vector<vector<char>> &board, int x, int y)
    {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'E')
            return;
        board[x][y] = '0' + getBombCount(board, x, y);
        if (board[x][y] == '0')
        {
            board[x][y] = 'B';
            dfs(board, x - 1, y - 1);
            dfs(board, x - 1, y);
            dfs(board, x - 1, y + 1);
            dfs(board, x, y - 1);
            dfs(board, x, y + 1);
            dfs(board, x + 1, y - 1);
            dfs(board, x + 1, y);
            dfs(board, x + 1, y + 1);
        }
    }
    int getBombCount(const vector<vector<char>> &board, int x, int y)
    {
        int result = 0;
        int m = board.size();
        int n = board[0].size();
        auto checkBomb = [&](int x, int y)
        {
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M')
                result++;
        };
        checkBomb(x - 1, y - 1);
        checkBomb(x - 1, y);
        checkBomb(x - 1, y + 1);
        checkBomb(x, y - 1);
        checkBomb(x, y + 1);
        checkBomb(x + 1, y - 1);
        checkBomb(x + 1, y);
        checkBomb(x + 1, y + 1);
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<char>> board = {
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
    };
    vector<int> click = {3, 0};
    vector<vector<char>> output = {
        {'B', '1', 'E', '1', 'B'},
        {'B', '1', 'M', '1', 'B'},
        {'B', '1', '1', '1', 'B'},
        {'B', 'B', 'B', 'B', 'B'},
    };
    EXPECT_EQ(solution.updateBoard(board, click), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<char>> board = {
        {'B', '1', 'E', '1', 'B'},
        {'B', '1', 'M', '1', 'B'},
        {'B', '1', '1', '1', 'B'},
        {'B', 'B', 'B', 'B', 'B'},
    };
    vector<int> click = {1, 2};
    vector<vector<char>> output = {
        {'B', '1', 'E', '1', 'B'},
        {'B', '1', 'X', '1', 'B'},
        {'B', '1', '1', '1', 'B'},
        {'B', 'B', 'B', 'B', 'B'},
    };
    EXPECT_EQ(solution.updateBoard(board, click), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<char>> board = {
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'M'},
        {'E', 'E', 'M', 'E', 'E', 'E', 'E', 'E'},
        {'M', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'M', 'E', 'E', 'E', 'E'},
    };
    vector<int> click = {0, 0};
    vector<vector<char>> output = {
        {'B', 'B', 'B', 'B', 'B', 'B', '1', 'E'},
        {'B', '1', '1', '1', 'B', 'B', '1', 'M'},
        {'1', '2', 'M', '1', 'B', 'B', '1', '1'},
        {'M', '2', '1', '1', 'B', 'B', 'B', 'B'},
        {'1', '1', 'B', 'B', 'B', 'B', 'B', 'B'},
        {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
        {'B', '1', '2', '2', '1', 'B', 'B', 'B'},
        {'B', '1', 'M', 'M', '1', 'B', 'B', 'B'},
    };
    EXPECT_EQ(solution.updateBoard(board, click), output);
}
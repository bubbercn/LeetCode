#pragma once
#include "Common.h"

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        size_t m = board.size();
        size_t n = 0;
        if (m != 0)
            n = board[0].size();

        if (m == 0 || n == 0)
            return;

        vector<tuple<size_t, size_t, size_t, size_t>> edges = {
            {0, 0, 0, n - 1},
            {0, n - 1, m - 1, n - 1},
            {m - 1, 0, m - 1, n - 1},
            {0, 0, m - 1, 0},
        };

        queue<pair<size_t, size_t>> oQueue;
        for (auto edge : edges)
        {
            for (int i = get<0>(edge); i <= get<2>(edge); i++)
            {
                for (int j = get<1>(edge); j <= get<3>(edge); j++)
                {
                    if (board[i][j] == 'O')
                    {
                        oQueue.push({i, j});
                    }
                }
            }
        }

        while (!oQueue.empty())
        {
            auto aO = oQueue.front();
            oQueue.pop();
            board[aO.first][aO.second] = 'o';
            vector<pair<size_t, size_t>> adjacentPoints = {
                {aO.first - 1, aO.second},
                {aO.first + 1, aO.second},
                {aO.first, aO.second - 1},
                {aO.first, aO.second + 1},
            };
            for (auto point : adjacentPoints)
            {
                if (point.first < m && point.second < n && board[point.first][point.second] == 'O')
                    oQueue.emplace(point);
            }
        }

        for (auto& i : board)
        {
            for (auto& j : i)
            {
                if (j == 'o')
                {
                    j = 'O';
                }
                else if (j == 'O')
                {
                    j = 'X';
                }
            }
        }
    }
};

void Test()
{
    Solution solution;
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    solution.solve(board);
}

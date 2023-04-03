#pragma once
#include "Common.h"

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        bool forward = true;
        unordered_map<int, int> lookup;
        int value = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (forward)
            {
                for (int j = 0; j < n; j++, value++)
                {
                    if (board[i][j] != -1)
                        lookup[value] = board[i][j];
                }
            }
            else
            {
                for (int j = n - 1; j >= 0; j--, value++)
                {
                    if (board[i][j] != -1)
                        lookup[value] = board[i][j];
                }
            }
            forward = !forward;
        }
        int result = 0;
        vector<bool> visited(n * n + 1);
        list<int> cur = {1};
        visited[1] = true;
        int target = n * n;
        while (!cur.empty())
        {
            result++;
            list<int> next;
            for (auto begin : cur)
            {
                for (int i = 1; i <= 6; i++)
                {
                    int end = begin + i;
                    if (auto it = lookup.find(end); it != lookup.end())
                    {
                        end = it->second;
                    }

                    if (end == target)
                        return result;

                    if (visited[end])
                        continue;

                    visited[end] = true;
                    next.emplace_back(end);
                }
            }
            cur.swap(next);
        }
        return -1;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1},
    };
    EXPECT_EQ(solution.snakesAndLadders(board), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> board = {
        {-1, -1},
        {-1, 3},
    };
    EXPECT_EQ(solution.snakesAndLadders(board), 1);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        vector<vector<int>> target = {{1, 2, 3}, {4, 5, 0}};
        if (board == target)
            return 0;

        int result = 1;
        unordered_set<int> visited;
        visited.emplace(hash(board));
        list<vector<vector<int>>> next = {board};
        while (!next.empty())
        {
            list<vector<vector<int>>> nextNext;
            for (auto &cur : next)
            {
                for (int i = 0; i < 2; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        if (cur[i][j] == 0)
                        {
                            vector<vector<int>> nextBoard = cur;
                            for (auto &dir : directions)
                            {
                                int x = i + dir.first;
                                int y = j + dir.second;
                                if (x >= 0 && x < 2 && y >= 0 && y < 3)
                                {
                                    swap(nextBoard[i][j], nextBoard[x][y]);
                                    if (nextBoard == target)
                                        return result;
                                    int hashValue = hash(nextBoard);
                                    if (visited.emplace(hashValue).second)
                                        nextNext.emplace_back(nextBoard);
                                    swap(nextBoard[i][j], nextBoard[x][y]);
                                }
                            }
                        }
                    }
                }
            }
            next.swap(nextNext);
            ++result;
        }
        return -1;
    }

private:
    inline static vector<pair<int, int>> directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}};
    int hash(const vector<vector<int>> &board)
    {
        int result = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                result = result * 10 + board[i][j];
            }
        }
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
    vector<vector<int>> board = {
        {1, 2, 3},
        {4, 0, 5},
    };
    EXPECT_EQ(solution.slidingPuzzle(board), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> board = {
        {1, 2, 3},
        {5, 4, 0},
    };
    EXPECT_EQ(solution.slidingPuzzle(board), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> board = {
        {4, 1, 2},
        {5, 0, 3},
    };
    EXPECT_EQ(solution.slidingPuzzle(board), 5);
}

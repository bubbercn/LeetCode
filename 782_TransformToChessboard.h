#pragma once
#include "Common.h"

class Solution
{
public:
    int movesToChessboard(vector<vector<int>> &board)
    {
        return 0;
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
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
    };
    EXPECT_EQ(solution.movesToChessboard(board), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> board = {
        {0, 1},
        {1, 0},
    };
    EXPECT_EQ(solution.movesToChessboard(board), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> board = {
        {1, 0},
        {1, 0},
    };
    EXPECT_EQ(solution.movesToChessboard(board), -1);
}
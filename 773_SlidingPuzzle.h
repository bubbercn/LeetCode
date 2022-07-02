#pragma once
#include "Common.h"

class Solution
{
public:
    int slidingPuzzle(vector<vector<int>> &board)
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

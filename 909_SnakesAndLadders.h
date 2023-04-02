#pragma once
#include "Common.h"

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
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
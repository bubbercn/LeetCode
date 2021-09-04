#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        return {};
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
        { 'E', 'E', 'E', 'E', 'E' },
        { 'E', 'E', 'M', 'E', 'E' },
        { 'E', 'E', 'E', 'E', 'E' },
        { 'E', 'E', 'E', 'E', 'E' },
    };
    vector<int> click = { 3, 0 };
    vector<vector<char>> output = {
        { 'B', '1', 'E', '1', 'B' },
        { 'B', '1', 'M', '1', 'B' },
        { 'B', '1', '1', '1', 'B' },
        { 'B', 'B', 'B', 'B', 'B' },
    };
    EXPECT_EQ(solution.updateBoard(board, click), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<char>> board = {
        { 'B', '1', 'E', '1', 'B' },
        { 'B', '1', 'M', '1', 'B' },
        { 'B', '1', '1', '1', 'B' },
        { 'B', 'B', 'B', 'B', 'B' },
    };
    vector<int> click = { 1, 2 };
    vector<vector<char>> output = {
        { 'B', '1', 'E', '1', 'B' },
        { 'B', '1', 'X', '1', 'B' },
        { 'B', '1', '1', '1', 'B' },
        { 'B', 'B', 'B', 'B', 'B' },
    };
    EXPECT_EQ(solution.updateBoard(board, click), output);
}
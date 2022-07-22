#pragma once
#include "Common.h"

class Solution
{
public:
    bool validTicTacToe(vector<string> &board)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> board = {
        "O  ",
        "   ",
        "   ",
    };
    EXPECT_EQ(solution.validTicTacToe(board), false);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> board = {
        "XOX",
        " X ",
        "   ",
    };
    EXPECT_EQ(solution.validTicTacToe(board), false);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> board = {
        "XOX",
        "O O",
        "XOX",
    };
    EXPECT_EQ(solution.validTicTacToe(board), true);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    bool validTicTacToe(vector<string> &board)
    {
        int countX = 0, countO = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 'X')
                {
                    countX++;
                }
                else if (board[i][j] == 'O')
                {
                    countO++;
                }
            }
        }
        if (countX > countO + 1 || countO > countX)
            return false;

        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                if (board[i][0] == ' ')
                    continue;
                if (board[i][0] == 'X')
                {
                    if (countX == countO)
                        return false;
                }
                else if (countX == countO + 1)
                    return false;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            {
                if (board[0][i] == ' ')
                    continue;
                if (board[0][i] == 'X')
                {
                    if (countX == countO)
                        return false;
                }
                else if (countX == countO + 1)
                    return false;
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        {
            if (board[0][0] == 'X')
            {
                if (countX == countO)
                    return false;
            }
            else if (countX == countO + 1)
                return false;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        {
            if (board[0][2] == 'X')
            {
                if (countX == countO)
                    return false;
            }
            else if (countX == countO + 1)
                return false;
        }
        return true;
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

TEST_F(LeetCodeTest, Failure1)
{
    vector<string> board = {
        "   ",
        "   ",
        "   ",
    };
    EXPECT_EQ(solution.validTicTacToe(board), true);
}
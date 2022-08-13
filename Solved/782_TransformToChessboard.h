#pragma once
#include "Common.h"

class Solution
{
public:
    int movesToChessboard(vector<vector<int>> &board)
    {
        int n = board.size();

        // examin first row and first column
        int count0 = 0, count1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 0)
                count0++;
            else
                count1++;
        }
        if (abs(count0 - count1) > 1)
            return -1;
        int rowMajority = 0;
        if (n % 2 != 0)
        {
            rowMajority = count0 > count1 ? 0 : 1;
        }

        count0 = 0, count1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 0)
                count0++;
            else
                count1++;
        }
        if (abs(count0 - count1) > 1)
            return -1;
        int colMajority = 0;
        if (n % 2 != 0)
        {
            colMajority = count0 > count1 ? 0 : 1;
        }

        // check rows are either the same as the first row or the opposite of the first row
        vector<int> notFirstRow(n, 0);
        for (int i = 0; i < n; i++)
        {
            notFirstRow[i] = board[0][i] ? 0 : 1;
        }

        for (int i = 1; i < n; i++)
        {
            if (board[i] != board[0] && board[i] != notFirstRow)
                return -1;
        }

        // calculate minimum move count for the first row and first column
        int result = 0;
        if (n % 2 == 0)
        {
            int minMove0 = 0;
            int minMove1 = 0;
            for (int i = 0; i < n; i += 2)
            {
                if (board[0][i] != 0)
                    minMove0++;
                else
                    minMove1++;
            }
            result += min(minMove0, minMove1);
            minMove0 = 0;
            minMove1 = 0;
            for (int i = 0; i < n; i += 2)
            {
                if (board[i][0] != 0)
                    minMove0++;
                else
                    minMove1++;
            }
            result += min(minMove0, minMove1);
        }
        else
        {
            for (int i = 0; i < n; i += 2)
            {
                if (board[0][i] != rowMajority)
                    result++;
            }
            for (int i = 0; i < n; i += 2)
            {
                if (board[i][0] != colMajority)
                    result++;
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

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> board = {
        {1, 0, 0},
        {0, 1, 1},
        {1, 0, 0},
    };
    EXPECT_EQ(solution.movesToChessboard(board), 1);
}
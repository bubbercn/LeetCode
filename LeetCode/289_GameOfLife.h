#pragma once
#include "Common.h"

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        const static vector<int> x = {-1, 0, 1, -1, 1, -1, 0, 1};
        const static vector<int> y = {-1, -1, -1, 0, 0, 1, 1, 1};
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                int alive = 0;

                for (int k = 0; k < 8; k++)
                {
                    int xx = i + x[k];
                    int yy = j + y[k];
                    if (xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size())
                    {
                        alive += board[xx][yy] & 1;
                    }
                }
                if (board[i][j] == 1)
                {
                    if (alive < 2)
                    {
                        ;
                    }
                    else if (alive == 2 || alive == 3)
                    {
                        board[i][j] |= 2;
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    if (alive == 3)
                    {
                        board[i][j] |= 2;
                    }
                    else
                    {
                        ;
                    }
                }
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                board[i][j] >>= 1;
            }
        }
    }
};

void Test()
{
}
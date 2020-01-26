#pragma once
#include "Common.h"

class Solution
{
public:
    int totalNQueens(int n)
    {
        Init(n);
        Process();
        return mResult;
    }
private:
    vector<vector<int>> mChessBoard;
    int mQueens;
    int mResult;
    int N;
    
    void Init(int n)
    {
        mChessBoard = vector<vector<int>>(n, vector<int>(n, 0));
        mQueens = 0;
        mResult = 0;
        N = n;
    }
    
    void Process()
    {
        if (mQueens == N)
        {
            AddResult();
            return;
        }
        for (int i = 0; i < N; i++)
        {
            if (mChessBoard[mQueens][i] == 0)
            {
                PlaceQueen(i);
                Process();
                Cleanup(i);
            }
        }
    }
    
    void PlaceQueen(int n)
    {
        for (int i = 0; i < N; i++)
        {
            mChessBoard[mQueens][i]++;
        }
        for (int i = 0; i < N; i++)
        {
            mChessBoard[i][n]++;
        }
        for (int i = mQueens - 1, j = n - 1; i >= 0 && j >= 0; i--, j--)
        {
            mChessBoard[i][j]++;
        }
        for (int i = mQueens + 1, j = n - 1; i <  N && j >= 0; i++, j--)
        {
            mChessBoard[i][j]++;
        }
        for (int i = mQueens + 1, j = n + 1; i <  N && j < N; i++, j++)
        {
            mChessBoard[i][j]++;
        }
        for (int i = mQueens - 1, j = n + 1; i >=  0 && j < N; i--, j++)
        {
            mChessBoard[i][j]++;
        }
        mChessBoard[mQueens][n] = -1;
        mQueens++;
    }
    
    void Cleanup(int n)
    {
        mQueens--;
        for (int i = 0; i < N; i++)
        {
            mChessBoard[mQueens][i]--;
        }
        for (int i = 0; i < N; i++)
        {
            mChessBoard[i][n]--;
        }
        for (int i = mQueens - 1, j = n - 1; i >= 0 && j >= 0; i--, j--)
        {
            mChessBoard[i][j]--;
        }
        for (int i = mQueens + 1, j = n - 1; i <  N && j >= 0; i++, j--)
        {
            mChessBoard[i][j]--;
        }
        for (int i = mQueens + 1, j = n + 1; i <  N && j < N; i++, j++)
        {
            mChessBoard[i][j]--;
        }
        for (int i = mQueens - 1, j = n + 1; i >=  0 && j < N; i--, j++)
        {
            mChessBoard[i][j]--;
        }
        mChessBoard[mQueens][n] = 0;
    }
    
    void AddResult()
    {
        mResult++;
    }
};

void Test()
{
    Solution solution;
    cout << solution.totalNQueens(8) << endl;
}


#pragma once
#include "Common.h"

class Solution
{
public:
    bool duplicate(vector<int>& input)
    {
        sort(input.begin(), input.end());
        for (int i = 0; i < 8; i++)
        {
            if (input[i] && input[i] == input[i + 1])
                return true;
        }
        return false;
    }
    
    bool validRow(int rowIndex)
    {
        vector<int> temp;
        temp.reserve(9);
        
        for (int i = 0; i < 9; i++)
        {
            temp.push_back(mBoard[rowIndex][i]);
        }
        
        return !duplicate(temp);
    }
    
    bool validColumn(int columnIndex)
    {
        vector<int> temp;
        temp.reserve(9);
        
        for (int i = 0; i < 9; i++)
        {
            temp.push_back(mBoard[i][columnIndex]);
        }
        
        return !duplicate(temp);
    }
    
    bool validGrid(int rowIndex, int columnIndex)
    {
        vector<int> temp;
        temp.reserve(9);
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp.push_back(mBoard[rowIndex + i][columnIndex + j]);
            }
        }
        
        return !duplicate(temp);
    }
    
    bool isValidSudoku(vector<vector<char>>& board)
	{
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    mBoard[i][j] = board[i][j] - '0';
                }
                else
                {
                    mBoard[i][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < 9; i++)
        {
            if (!validRow(i))
                return false;
        }
        
        for (int i = 0; i < 9; i++)
        {
            if (!validColumn(i))
                return false;
        }
        
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                if (!validGrid(i, j))
                    return false;
            }
        }
        
        return true;
	}
    
    int mBoard[9][9];
};

void Test()
{
    vector<vector<char>> input1 =
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    vector<vector<char>> input2 =
    {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    Solution solution;
 
    assert(solution.isValidSudoku(input1));
    assert(!solution.isValidSudoku(input2));
}

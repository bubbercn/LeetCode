#pragma once
#include "Common.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        initBoard(board);
        
        stack<pair<pair<int, int>, vector<int>>> steps;
        
        auto position = make_pair(0, 0);
        
        do
        {
            position = findNextSlot(position.first, position.second);
            
            if (position.first == -1)
                break;
            
            vector<int> possibleNumbers = getPossibleNumbers(position.first, position.second);
            
            if (possibleNumbers.size() > 0)
            {
                mBoard[position.first][position.second] = *possibleNumbers.begin();
                possibleNumbers.erase(possibleNumbers.begin());
                steps.push(make_pair(position, possibleNumbers));
            }
            else
            {
                while (steps.top().second.size() == 0)
                {
                    position = steps.top().first;
                    mBoard[position.first][position.second] = 0;
                    steps.pop();
                }
                position = steps.top().first;
                mBoard[position.first][position.second] = *steps.top().second.begin();
                steps.top().second.erase(steps.top().second.begin());
            }
        }
        while (true);
        
        outputTransform(board);
    }
    
private:
    void initBoard(const vector<vector<char>>& board)
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
    }
    
    pair<int, int> findNextSlot(int x, int y)
    {
        for (int i = x; i < 9; i++)
        {
            for (int j = (i == x ? y : 0); j < 9; j++)
            {
                if (mBoard[i][j] == 0)
                    return make_pair(i, j);
            }
        }
        return make_pair(-1, -1);
    }
    
    vector<int> getPossibleNumbers(int x, int y)
    {
        bool numbers[10] = {true, true, true, true, true, true, true, true, true, true};
        for (int i = 0; i < 9; i++)
        {
            numbers[mBoard[x][i]] = false;
        }
        for (int i = 0; i < 9; i++)
        {
            numbers[mBoard[i][y]] = false;
        }
        x -= x%3;
        y -= y%3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                numbers[mBoard[x + i][y + j]] = false;
            }
        }
        vector<int> result;
        for (int i = 1; i < 10; i++)
        {
            if (numbers[i])
            {
                result.push_back(i);
            }
        }
        return result;
    }
    
    void outputTransform(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                board[i][j] = '0' + mBoard[i][j];
            }
        }
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
    
    vector<vector<char>> output1 =
    {
        {'5','3','4','6','7','8','9','1','2'},
        {'6','7','2','1','9','5','3','4','8'},
        {'1','9','8','3','4','2','5','6','7'},
        {'8','5','9','7','6','1','4','2','3'},
        {'4','2','6','8','5','3','7','9','1'},
        {'7','1','3','9','2','4','8','5','6'},
        {'9','6','1','5','3','7','2','8','4'},
        {'2','8','7','4','1','9','6','3','5'},
        {'3','4','5','2','8','6','1','7','9'}
    };

    
    Solution solution;
    solution.solveSudoku(input1);
    
    assert(input1 == output1);
}

#pragma once
#include "Common.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0)
            return;
        
        if ((*matrix.begin()).size() == 0)
            return;
        
        size_t m = matrix.size();
        size_t n = (*matrix.begin()).size();
        
        bool x = false, y = false;
        
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                x = true;
                break;
            }
        }
        
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                y = true;
                break;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for (int j = 1; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < m; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (x)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
        
        if (y)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }
};

void Test()
{
    Solution solution;
    vector<vector<int>> input =
    {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    solution.setZeroes(input);
}

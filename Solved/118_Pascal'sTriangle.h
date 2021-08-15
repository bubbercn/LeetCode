#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        
        for (int i = 1; i <= numRows; i++)
        {
            vector<int> row;
            if (i == 1)
            {
                row = {1};
            }
            else
            {
                vector<int>& preRow = *result.rbegin();
                for (int j = 0; j < i; j++)
                {
                    if(j == 0)
                    {
                        row.emplace_back(preRow[0]);
                    }
                    else if (j == i - 1)
                    {
                        row.emplace_back(preRow[i - 2]);
                    }
                    else
                    {
                        row.emplace_back(preRow[j - 1] + preRow[j]);
                    }
                }
            }
            result.emplace_back(row);
        }
        
        return result;
    }
};

void Test()
{
    Solution solution;
    solution.generate(5);
}

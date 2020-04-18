#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> row;
        
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> temp;
            if (i == 0)
            {
                temp = {1};
            }
            else
            {
                for (int j = 0; j <= i; j++)
                {
                    if(j == 0)
                    {
                        temp.emplace_back(row[0]);
                    }
                    else if (j == i)
                    {
                        temp.emplace_back(row[i - 1]);
                    }
                    else
                    {
                        temp.emplace_back(row[j - 1] + row[j]);
                    }
                }
            }
            row.swap(temp);
        }
        
        return row;
    }
};

void Test()
{
    Solution solution;
    solution.getRow(3);
}

#pragma once
#include "Common.h"

class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        if (triangle.empty())
            return 0;
        
        vector<int> distances;
        
        for (int i = 0; i < triangle.size(); i++)
        {
            vector<int> temp(triangle.size(), 0);
            if (i == 0)
            {
                temp[0] = triangle[0][0];
            }
            else
            {
                for (int j = 0; j <= i; j++)
                {
                    if(j == 0)
                    {
                        temp[0] = distances[0] + triangle[i][0];
                    }
                    else if (j == i)
                    {
                        temp[i] = distances[i - 1] + triangle[i][i];
                    }
                    else
                    {
                        temp[j] = min(distances[j - 1], distances[j]) + triangle[i][j];
                    }
                }
            }
            distances.swap(temp);
        }
        
        int min = distances[0];
        for (int i = 1; i < distances.size(); i++)
        {
            if (distances[i] < min)
                min = distances[i];
        }
        
        return min;
    }
};

void Test()
{
    Solution solution;
    
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    assert(solution.minimumTotal(triangle) == 11);
}

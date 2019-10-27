#pragma once
#include "Common.h"

class Solution {
public:
    int jump(vector<int>& nums)
    {
        size_t length = nums.size();
        vector<vector<size_t>> adjacentMatrix(length);
        
        for (auto& i : adjacentMatrix)
        {
            i.assign(length, -1);
        }
        
        for (int i = 0; i < length; i++)
        {
            adjacentMatrix[i][i] = 0;
            for (int j = 1; j <= nums[i] && i + j < length; j++)
            {
                adjacentMatrix[i][i + j] = 1;
            }
        }
        
        for (size_t k = 0; k < length; k++)
        {
            for (size_t i = 0; i < length; i++)
            {
                for (size_t j = i + 1; j < length; j++)
                {
                    if (k <= i || k >= j)
                    {
                        continue;
                    }
                    
                    if (adjacentMatrix[i][k] != -1 && adjacentMatrix[k][j] != -1 && adjacentMatrix[i][k] + adjacentMatrix[k][j] < adjacentMatrix[i][j])
                    {
                        adjacentMatrix[i][j] = adjacentMatrix[i][k] + adjacentMatrix[k][j];
                    }
                }
            }
        }
        
        return static_cast<int>(adjacentMatrix[0][length - 1]);
    }
};

void Test()
{
    Solution solution;
    vector<int> input = {2, 3, 1, 1, 4};
    assert(solution.jump(input) == 2);
    
    input = {2};
    assert(solution.jump(input) == 0);
}


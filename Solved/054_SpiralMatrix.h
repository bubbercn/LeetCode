#pragma once
#include "Common.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> result;
        size_t top = 0, left = 0;
        size_t bottom = matrix.size();
        if (bottom == 0)
        {
            return {};
        }
        size_t right = matrix.begin()->size();
        size_t x = 0, y = 0;
        size_t direction = 0;
        while (top < bottom && left < right)
        {
            switch (direction % 4)
            {
                case 0:
                {
                    while (y >= left && y < right)
                    {
                        result.emplace_back(matrix[x][y]);
                        y++;
                    }
                    y--;
                    top++;
                    x++;
                }
                    break;
                case 1:
                {
                    while (x >= top && x < bottom)
                    {
                        result.emplace_back(matrix[x][y]);
                        x++;
                    }
                    x--;
                    right--;
                    y--;
                }
                    break;
                case 2:
                {
                    while (y >= left && y < right)
                    {
                        result.emplace_back(matrix[x][y]);
                        y--;
                    }
                    y++;
                    bottom--;
                    x--;
                }
                    break;
                case 3:
                {
                    while (x >= top && x < bottom)
                    {
                        result.emplace_back(matrix[x][y]);
                        x--;
                    }
                    x++;
                    left++;
                    y++;
                }
                    break;
                default:
                    break;
            }
            direction++;
        }
        return result;
    }
};

void Test()
{
    Solution solution;
    vector<vector<int>> input1 = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    vector<int> output1 = {1,2,3,6,9,8,7,4,5};
    assert(solution.spiralOrder(input1) == output1);
 
    vector<vector<int>> input2 = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8},
        { 9, 10, 11, 12}
    };
    vector<int> output2 = {1,2,3,4,8,12,11,10,9,5,6,7};
    assert(solution.spiralOrder(input2) == output2);
}

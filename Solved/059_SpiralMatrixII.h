#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        size_t top = 0, left = 0;
        size_t bottom = n;
        size_t right = n;
        size_t x = 0, y = 0;
        size_t direction = 0;
        int temp = 0;
        while (top < bottom && left < right)
        {
            switch (direction % 4)
            {
                case 0:
                {
                    while (y >= left && y < right)
                    {
                        result[x][y] = ++temp;
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
                        result[x][y] = ++temp;
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
                        result[x][y] = ++temp;
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
                        result[x][y] = ++temp;
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
    solution.generateMatrix(2);
    solution.generateMatrix(3);
}

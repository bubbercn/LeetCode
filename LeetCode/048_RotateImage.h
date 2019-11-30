#pragma once
#include "Common.h"

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        size_t length = matrix.size();
        size_t half = length / 2;
        for (size_t i = 0; i < half; i++)
        {
            for (size_t j = i; j < length - i - 1; j++)
            {
                swap(matrix[i][j], matrix[j][length - i - 1]);
                swap(matrix[i][j], matrix[length - i - 1][length - 1 - j]);
                swap(matrix[i][j], matrix[length - 1 - j][i]);
            }
        }
    }
};

void Test()
{
    Solution solution;
    
    vector<vector<int>> input1 =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    vector<vector<int>> output1 =
    {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3}
    };
    
    solution.rotate(input1);
    assert(input1 == output1);
    
    vector<vector<int>> input2 =
    {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    
    vector<vector<int>> output2 =
    {
        {15, 13, 2, 5},
        {14, 3, 4, 1},
        {12, 6, 8, 9},
        {16, 7, 10, 11}
    };
    
    solution.rotate(input2);
    assert(input2 == output2);
}

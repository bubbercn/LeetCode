#pragma once
#include "Common.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        
        if ((*matrix.begin()).size() == 0)
            return false;

        int found = binarySearch1(matrix, target);
        
        if (found == -1)
            return false;
        
        return binarySearch2(matrix[found], target);
    }
private:
    int binarySearch1(vector<vector<int>>& matrix, int target)
    {
        int left = 0, right = matrix.size() - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (*matrix[middle].begin() <= target && *matrix[middle].rbegin() >= target)
            {
                return middle;
            }
            else if (*matrix[middle].begin() > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return -1;
    }
    
    bool binarySearch2(vector<int> matrix, int target)
    {
        int left = 0, right = matrix.size();
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (matrix[middle] == target)
            {
                return true;
            }
            else if (matrix[middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return false;
    }
};

void Test()
{
    Solution solution;
//    vector<vector<int>> matrix = {
//        {1,   3,  5,  7},
//        {10, 11, 16, 20},
//        {23, 30, 34, 50}
//    };
//    assert(solution.searchMatrix(matrix, 3));
//    assert(!solution.searchMatrix(matrix, 13));
    
    vector<vector<int>> matrix = {{1}};
    assert(!solution.searchMatrix(matrix, 0));
    
}

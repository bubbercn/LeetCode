#pragma once
#include "Common.h"

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> paths(m, 1);
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                paths[j] = paths[j - 1] + paths[j];
            }
        }
        
        return paths[m - 1];
    }
};

void Test()
{
    Solution solution;
    assert(solution.uniquePaths(3, 2) == 3);
}

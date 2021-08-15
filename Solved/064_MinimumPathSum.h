#pragma once
#include "Common.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        size_t m, n;
        m = grid.size();
        if (m == 0)
            return 0;
        
        n = grid[0].size();
        
        vector<int> sum(n, 0);
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0)
                {
                    if (j == 0)
                    {
                        sum[j] = grid[i][j];
                    }
                    else
                    {
                        sum[j] = sum[j - 1] + grid[i][j];
                    }
                }
                else
                {
                    if (j == 0)
                    {
                        sum[j] += grid[i][j];
                    }
                    else
                    {
                        sum[j] = min(sum[j], sum[j - 1]) + grid[i][j];
                    }
                }
            }
        }
        
        return sum[n - 1];
    }
};

void Test()
{
    vector<vector<int>> input =
    {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    Solution solution;
    assert(solution.minPathSum(input) == 7);
}


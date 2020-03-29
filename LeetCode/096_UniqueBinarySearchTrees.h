#pragma once
#include "Common.h"

class Solution {
public:
    int numTrees(int n) 
    {
        vector<int> result(n + 1);
        result[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int temp = 0;
            for (int j = 0; j < i; j++)
            {
                temp += result[j] * result[i - j - 1];
            }
            result[i] = temp;
        }

        return result[n];    
    }
};

void Test()
{
    Solution solution;
    assert(solution.numTrees(3) == 5);
}
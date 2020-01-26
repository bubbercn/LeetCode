#pragma once
#include "Common.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int sum = *nums.begin();
        int max = sum;
        
        if (sum < 0)
        {
            sum = 0;
        }
        
        for (auto i = ++nums.begin(); i < nums.end(); i++)
        {
            sum += *i;
            if (sum > max)
            {
                max = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        
        return max;
    }
};
void Test()
{
    Solution solution;
    
    vector<int> input = {-2, 1, -3, 4, -1 ,2 ,1, -5, 4};
    assert(solution.maxSubArray(input) == 6);
}

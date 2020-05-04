#pragma once
#include "Common.h"

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int result = 0;
        for (auto i : nums)
        {
            result ^= i;
        }
        return result;
    }
};

void Test()
{
    Solution solution;
    vector<int> nums;
    
    nums = {2, 2, 1};
    assert(solution.singleNumber(nums) == 1);
    
    nums = {4, 1, 2, 1, 2};
    assert(solution.singleNumber(nums) == 4);
}

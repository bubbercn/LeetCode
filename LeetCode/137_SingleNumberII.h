#pragma once
#include "Common.h"

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        constexpr int numOfBits = 8 * sizeof(int);
        vector<int> bitsStats(numOfBits, 0);
        for (auto i : nums)
        {
            for (int j = 0; j < numOfBits; j++)
            {
                if (i & (1 << j))
                {
                    bitsStats[j]++;
                }
            }
        }
        for (auto& i : bitsStats)
        {
            i = i % 3;
        }
        int result = 0;
        for (int i = 0; i < numOfBits; i++)
        {
            if(bitsStats[i] != 0)
            {
                result ^= (1 << i);
            }
        }
        return result;
    }
};

void Test()
{
    Solution solution;
    vector<int> nums;
    
    nums = {2, 2, 3, 2};
    assert(solution.singleNumber(nums) == 3);
    
    nums = {0,1,0,1,0,1,99};
    assert(solution.singleNumber(nums) == 99);
}

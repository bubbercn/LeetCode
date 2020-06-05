#pragma once
#include "Common.h"

class Solution
{
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int min = INT_MAX;
        int sum = 0;
        int length = 0;
        for (int begin = 0, end = 0; begin <= end && end < nums.size(); end++)
        {
            sum += nums[end];
            length++;
            if (sum >= s)
            {
                min = ::min(min, length);
                while (begin < end)
                {
                    sum -= nums[begin];
                    length--;
                    begin++;
                    if (sum >= s)
                    {
                        min = ::min(min, length);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return min == INT_MAX ? 0 : min;
    }
};

void Test()
{
    Solution solution;
    int s = 7;
    vector<int> nums = {2,3,1,2,4,3};
    
    assert(solution.minSubArrayLen(s, nums) == 2);
}

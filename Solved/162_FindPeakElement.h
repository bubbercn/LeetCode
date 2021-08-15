#pragma once
#include "Common.h"

class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        
        int begin = 0, end = static_cast<int>(nums.size()) - 1;
        
        while (begin <= end)
        {
            if (begin == end)
            {
                return begin;
            }
            
            if (end - begin == 1)
            {
                return nums[begin] > nums[end] ? begin : end;
            }
            
            int middle = (begin + end) / 2;
            if (nums[middle] > nums[middle - 1] && nums[middle] > nums[middle + 1])
            {
                return middle;
            }
            else
            {
                if (nums[middle - 1] > nums[middle])
                {
                    end = middle - 1;
                }
                else
                {
                    begin = middle + 1;
                }
            }
        }
        
        return 0;
    }
};

void Test()
{
    Solution solution;
    vector<int> nums;
    
    nums = {1,2,3,1};
    assert(solution.findPeakElement(nums) == 2);
    
    nums = {1,2,1,3,5,6,4};
    assert(solution.findPeakElement(nums) == 1 || solution.findPeakElement(nums) == 5);
    
    nums = {1,3,2,1};
    assert(solution.findPeakElement(nums) == 1);
}

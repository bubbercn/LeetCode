#pragma once
#include "Common.h"

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int begin = 0, end = static_cast<int>(nums.size()) - 1;
        
        while (begin <= end)
        {
            if (begin == end)
            {
                return nums[begin];
            }
            else if (end - begin == 1)
            {
                return min(nums[begin], nums[end]);
            }
            
            int middle = (begin + end) / 2;
            if (nums[middle] < nums[middle - 1])
            {
                return nums[middle];
            }
            else if (nums[middle] > nums[middle + 1])
            {
                return nums[middle + 1];
            }
            
            if (nums[begin] == nums[middle] && nums[middle] == nums[end])
            {
                end = end - 1;
            }
            else if ((nums[begin] <= nums[middle] && nums[middle] <= nums[end]) || nums[begin] > nums[middle])
            {
                end = middle - 1;
            }
            else if (nums[middle] > nums[end])
            {
                begin = middle + 1;
            }
        }
        
        return INT_MIN;
    }
};

void Test()
{
    Solution solution;
    vector<int> nums;
    
    assert(solution.findMin(nums) == INT_MIN);

    nums = {0};
    assert(solution.findMin(nums) == 0);

    nums = {3,4,5,1,2};
    assert(solution.findMin(nums) == 1);

    nums = {4,5,6,7,0,1,2};
    assert(solution.findMin(nums) == 0);
    
    nums = {0,1,2,4,5,6,7};
    assert(solution.findMin(nums) == 0);
    
    nums = {5,1,2,3,4};
    assert(solution.findMin(nums) == 1);
    
    nums = {3,3,3,3,3,3,3,3,1,3};
    assert(solution.findMin(nums) == 1);
    
    nums = {1,1,3};
    assert(solution.findMin(nums) == 1);
}

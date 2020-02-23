#pragma once
#include "Common.h"

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int left = 0;
        int right = static_cast<int>(nums.size() - 1);
        int endOf0 = left;
        int beginOf2 = right;
        
        while (left <= right)
        {
            if (nums[left] == 0)
            {
                swap(nums[left], nums[endOf0]);
                left++;
                endOf0++;
                continue;
            }
            if (nums[right] == 2)
            {
                swap(nums[right], nums[beginOf2]);
                right--;
                beginOf2--;
                continue;
            }
            if (nums[left] == 1 && nums[right] == 1)
            {
                left++;
                right--;
            }
            else if (nums[left] == 2 && nums[right] == 1)
            {
                swap(nums[left], nums[beginOf2]);
                left++;
                beginOf2--;
                if (right > beginOf2)
                    right = beginOf2;
            }
            else if (nums[left] == 1 && nums[right] == 0)
            {
                swap(nums[right], nums[endOf0]);
                endOf0++;
                right--;
                if (left < endOf0)
                    left = endOf0;
            }
            else if (nums[left] == 2 && nums[right] == 0)
            {
                swap(nums[left], nums[right]);
            }
        }
    }
};

void Test()
{
    Solution solution;
    vector<int> input = {2,0,2,1,1,0};
    vector<int> output = {0,0,1,1,2,2};
    solution.sortColors(input);
    assert(input == output);

    input = {2, 1, 0, 0};
    output = {0, 0, 1, 2};
    solution.sortColors(input);
    assert(input == output);

    input = {1, 2, 0};
    output = {0, 1, 2};
    solution.sortColors(input);
    assert(input == output);

    input = {0, 0, 2, 0, 0, 1, 0, 0};
    output = {0, 0, 0, 0, 0, 0, 1, 2};
    solution.sortColors(input);
    assert(input == output);
    
    input = {0,2,2,2,0,2,1,1};
    output = {0,0,1,1,2,2,2,2};
    solution.sortColors(input);
    assert(input == output);
    
    input = {2,2,1,2,1,1,1,0,0,2,1,0,2,1,2,2,1,1,1,1,1,0,2,0,2,0,2,2,1,0,2,1,0,2,1,2,0,0,0,0,2,1,1,2,0,1,2,2,0,0,2,2,0,1,0,1,0,0,1,1,1,0,0,2,2,2,1,0,0,2,1,0,1,0,2,2,1,2,1,1,2,1,1,0,0,2,1,0,0};
    solution.sortColors(input);
}

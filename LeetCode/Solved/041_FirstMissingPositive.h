#pragma once
#include "Common.h"

class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] >= 1 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        int result = 1;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == result)
            {
                result++;
            }
        }
        
        return result;
    }
};

void Test()
{
    Solution solution;
    
    vector<int> input1 = {1, 2, 0};
    assert(solution.firstMissingPositive(input1) == 3);

    vector<int> input2 = {3, 4, -1, 1};
    assert(solution.firstMissingPositive(input2) == 2);

    vector<int> input3 = {7, 8, 9, 11, 12};
    assert(solution.firstMissingPositive(input3) == 1);
    
    vector<int> input = {-1,4,2,1,9,10};
    assert(solution.firstMissingPositive(input) == 3);
}

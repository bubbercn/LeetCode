#pragma once
#include "Common.h"

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = lookup.find(nums[i]);
            if (it != lookup.end())
            {
                if (i - it->second <= k)
                {
                    return true;
                }
                it->second = i;
            }
            else
            {
                lookup[nums[i]] = i;
            }
        }
        return false;
    }
};

void Test()
{
    Solution solution;
    vector<int> nums;
    int k = 0;
    
    nums = {1,2,3,1};
    k = 3;
    assert(solution.containsNearbyDuplicate(nums, k) == true);
    
    nums = {1,0,1,1};
    k = 1;
    assert(solution.containsNearbyDuplicate(nums, k) == true);
    
    nums = {1,2,3,1,2,3};
    k = 2;
    assert(solution.containsNearbyDuplicate(nums, k) == false);
}

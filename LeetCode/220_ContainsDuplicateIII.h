#pragma once
#include "Common.h"

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        multiset<int> lookup;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto low = lookup.upper_bound(nums[i]);
            if (low != lookup.end() && *low + t >= nums[i])
                return true;
            
            auto high = lookup.lower_bound(nums[i]);
            if (high != lookup.end() && nums[i] + t >= *high)
                return true;
            
            lookup.emplace(nums[i]);
            if (lookup.size() > k)
            {
                lookup.erase(lookup.find(nums[i - k]));
            }
        }
        return false;
    }
};

void Test()
{
    Solution solution;
    vector<int> nums;
    int k = 0, t = 0;
    
    nums = {1,2,3,1};
//    k = 3;
//    t = 0;
//    assert(solution.containsNearbyAlmostDuplicate(nums, k, t) == true);
//
//    nums = {1,0,1,1};
//    k = 1;
//    t = 2;
//    assert(solution.containsNearbyAlmostDuplicate(nums, k, t) == true);
    
    nums = {1,2,3,1,2,3};
    k = 2;
    t = 3;
    assert(solution.containsNearbyAlmostDuplicate(nums, k, t) == false);
}

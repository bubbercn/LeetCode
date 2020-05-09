#pragma once
#include "Common.h"

class Solution
{
public:
    int maximumGap(vector<int>& nums)
    {
        nums = RemoveDuplicate(nums);
        
        if (nums.size() < 2)
            return 0;
        
        RadixSort(nums);
        
        int maxDiff = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxDiff = max(maxDiff, nums[i + 1] - nums[i]);
        }
        
        return maxDiff;
    }
private:
    vector<int> RemoveDuplicate(const vector<int>& nums)
    {
        unordered_set<int> lookup;
        for (auto i : nums)
        {
            lookup.emplace(i);
        }
        
        return {lookup.begin(), lookup.end()};
    }
    void RadixSort(vector<int>& nums)
    {
        int radix = 1;
        list<int> digitsList[10];
        
        while(true)
        {
            bool endLoop = true;
            vector<int> temp = nums;
            for (int i = 0; i < nums.size(); i++)
            {
                temp[i] /= radix;
                if (temp[i] > 0)
                    endLoop = false;
                temp[i] %= 10;
                digitsList[temp[i]].emplace_back(nums[i]);
            }
            if (endLoop)
                break;
            
            for (int i = 0, j = 0; i < 10; i++)
            {
                for (auto k : digitsList[i])
                {
                    nums[j++] = k;
                }
                digitsList[i].clear();
            }
            
            radix *= 10;
        }
    }
};

void Test()
{
    Solution solution;
    vector<int> nums;
    
    nums = {3,6,9,1};
    assert(solution.maximumGap(nums) == 3);
    
    nums = {10};
    assert(solution.maximumGap(nums) == 0);
    
    nums = {2,99999999};
    assert(solution.maximumGap(nums) == 99999997);
}

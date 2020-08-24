#pragma once
#include "Common.h"

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int maxLength = 0;
        set<int> increasingSequence;

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = increasingSequence.lower_bound(nums[i]);
            if (it != increasingSequence.end())
            {

                it = increasingSequence.erase(it);
            }
            increasingSequence.emplace_hint(it, nums[i]);
            maxLength = max(maxLength, static_cast<int>(increasingSequence.size()));
        }
        return maxLength;
    }
};

void Test()
{
    Solution solution;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    assert(solution.lengthOfLIS(nums) == 4);

    nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    assert(solution.lengthOfLIS(nums) == 6);
}

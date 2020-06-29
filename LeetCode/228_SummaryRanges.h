#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        if (nums.empty())
            return {};

        vector<string> result;
        int begin = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                pushRange(result, begin, nums[i - 1]);
                begin = nums[i];
            }
        }
        pushRange(result, begin, *nums.rbegin());
        return result;
    }

private:
    void pushRange(vector<string> &result, int begin, int end)
    {
        if (begin == end)
        {
            result.emplace_back(to_string(begin));
        }
        else
        {
            result.emplace_back(to_string(begin) + "->" + to_string(end));
        }
    }
};

void Test()
{
    Solution solution;

    vector<int> nums = {0,1,2,4,5,7};
    solution.summaryRanges(nums);

    nums = {0,2,3,4,6,8,9};
    solution.summaryRanges(nums);
}
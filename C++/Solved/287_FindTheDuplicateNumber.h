#pragma once
#include "Common.h"

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int left = 1;
        int right = static_cast<int>(nums.size() - 1);
        int count = static_cast<int>(nums.size());
        while (left <= right)
        {
            if (left == right)
                return left;

            int middle = left + (right - left) / 2;
            int average = count / 2;
            int nextCount = 0;
            for (auto i : nums)
            {
                if (i < left || i > right)
                    continue;
                if (i <= middle)
                {
                    nextCount++;
                }
            }
            if (nextCount > average)
            {
                right = middle;
                count = nextCount;
            }
            else
            {
                left = middle + 1;
                count -= nextCount;
            }
        }
        return 0;
    }
};

void Test()
{
    Solution solution;
    vector<int> nums;

    nums = {1, 3, 4, 2, 2};
    assert(solution.findDuplicate(nums) == 2);

    nums = {3, 1, 3, 4, 2};
    assert(solution.findDuplicate(nums) == 3);

    nums = {1, 3, 4, 2, 1};
    assert(solution.findDuplicate(nums) == 1);

    nums = {1, 4, 4, 2, 4};
    assert(solution.findDuplicate(nums) == 4);
}
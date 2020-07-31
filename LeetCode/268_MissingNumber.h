#pragma once
#include "Common.h"

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        nums.emplace_back(-1);
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i && nums[i] != -1)
            {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == -1)
                return i;
        }
        return -1;
    }
};

void Test()
{
}
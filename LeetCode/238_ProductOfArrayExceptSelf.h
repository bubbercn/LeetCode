#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> result(nums.size(), 1);
        for (int i = 1; i < result.size(); i++)
        {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int rightProduct = 1;
        for (int i = result.size() - 2; i >= 0; i--)
        {
            rightProduct *= nums[i + 1];
            result[i] *= rightProduct;
        }

        return result;
    }
};

void Test()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = {24, 12, 8, 6};
    assert(solution.productExceptSelf(nums) == result);
}
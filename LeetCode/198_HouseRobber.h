#pragma once
#include "Common.h"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp = vector<int>(2);
        int N = nums.size();
        for (int i = 0; i < N; i++)
        {
            if (i == 0)
            {
                dp[0] = 0;
                dp[1] = nums[i];
            }
            else
            {
                int temp = dp[0];
                dp[0] = max(dp[0], dp[1]);
                dp[1] = temp + nums[i];
            }
        }
        return max(dp[0], dp[1]);
    }
};

void Test()
{
    Solution solution;
    vector<int> nums;

    nums = {1, 2, 3, 1};
    assert(solution.rob(nums) == 4);

    nums = {2, 7, 9, 3, 1};
    assert(solution.rob(nums) == 12);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int N = nums.size();
        if (N == 0)
            return 0;
        if (N == 1)
            return nums[0];

        return max(helper(nums, 0, N - 1), helper(nums, 1, N));
    }

private:
    int helper(vector<int> &nums, int begin, int end)
    {
        vector<int> dp = vector<int>(2);

        for (int i = begin; i < end; i++)
        {
            if (i == begin)
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

    nums = {2,3,2};
    assert(solution.rob(nums) == 3);

    nums = {1,2,3,1};
    assert(solution.rob(nums) == 4);
}

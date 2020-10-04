#pragma once
#include "Common.h"

class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        multiset<long> preSums;
        preSums.emplace(0);
        long preSum = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            preSum += nums[i];
            result += distance(preSums.lower_bound(preSum - upper), preSums.upper_bound(preSum - lower));
            preSums.emplace(preSum);
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {-2, 5, -1};
    EXPECT_EQ(solution.countRangeSum(nums, -2, 2), 3);
}

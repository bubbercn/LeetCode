#pragma once
#include "Common.h"

class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> max(n);
        vector<int> min(n);
        max[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            max[i] = ::max(nums[i], max[i - 1]);
        }
        min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            min[i] = ::min(nums[i], min[i + 1]);
        }
        for (int i = 0; i < n; i++)
        {
            if (max[i] <= min[i + 1])
                return i + 1;
        }
        return -1;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {5, 0, 3, 8, 6};
    EXPECT_EQ(solution.partitionDisjoint(nums), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 1, 1, 0, 6, 12};
    EXPECT_EQ(solution.partitionDisjoint(nums), 4);
}
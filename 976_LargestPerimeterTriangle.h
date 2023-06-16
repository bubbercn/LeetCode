#pragma once
#include "Common.h"

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size() - 2;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < nums[i + 1] + nums[i + 2])
            {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {2, 1, 2};
    EXPECT_EQ(solution.largestPerimeter(nums), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 1, 10};
    EXPECT_EQ(solution.largestPerimeter(nums), 0);
}
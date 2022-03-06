#pragma once
#include "Common.h"

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it != nums.end() && *it == target)
            return distance(nums.begin(), it);
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
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(solution.search(nums, 9), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(solution.search(nums, 2), -1);
}
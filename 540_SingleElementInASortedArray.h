#pragma once
#include "Common.h"

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            result ^= nums[i];
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    EXPECT_EQ(solution.singleNonDuplicate(nums), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
    EXPECT_EQ(solution.singleNonDuplicate(nums), 10);
}
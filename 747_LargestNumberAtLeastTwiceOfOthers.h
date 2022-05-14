#pragma once
#include "Common.h"

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int first = nums[0];
        int firstIndex = 0;
        int second = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= second)
                continue;

            if (nums[i] < first)
            {
                second = nums[i];
                continue;
            }

            second = first;
            first = nums[i];
            firstIndex = i;
        }
        if (second == 0 || first >= 2 * second)
            return firstIndex;
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
    vector<int> nums = {3, 6, 1, 0};
    EXPECT_EQ(solution.dominantIndex(nums), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(solution.dominantIndex(nums), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1};
    EXPECT_EQ(solution.dominantIndex(nums), 0);
}
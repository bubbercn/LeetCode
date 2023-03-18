#pragma once
#include "Common.h"

class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        int state = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (state == 0)
            {
                if (nums[i] > nums[i - 1])
                {
                    state = 1;
                }
                else if (nums[i] < nums[i - 1])
                {
                    state = -1;
                }
            }
            else if (state == 1)
            {
                if (nums[i] < nums[i - 1])
                    return false;
            }
            else
            {
                if (nums[i] > nums[i - 1])
                    return false;
            }
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 2, 2, 3};
    EXPECT_EQ(solution.isMonotonic(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {6, 5, 4, 4};
    EXPECT_EQ(solution.isMonotonic(nums), true);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 3, 2};
    EXPECT_EQ(solution.isMonotonic(nums), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {1, 1, 2};
    EXPECT_EQ(solution.isMonotonic(nums), true);
}

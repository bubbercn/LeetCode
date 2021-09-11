#pragma once
#include "Common.h"

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            if (right == left + 1)
                return nums[left];

            int middle = (left + right) / 2;
            if (nums[middle] == nums[middle - 1])
            {
                if ((middle - 1) % 2 != 0)
                {
                    right = middle - 1;
                }
                else
                {
                    left = middle + 1;
                }
            }
            else if (nums[middle] == nums[middle + 1])
            {
                if (middle % 2 != 0)
                {
                    right = middle;
                }
                else
                {
                    left = middle + 2;
                }
            }
            else
            {
                return nums[middle];
            }
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
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    EXPECT_EQ(solution.singleNonDuplicate(nums), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
    EXPECT_EQ(solution.singleNonDuplicate(nums), 10);
}
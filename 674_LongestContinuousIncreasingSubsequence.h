#pragma once
#include "Common.h"

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int result = 0;
        int length = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                length++;
            }
            else if (nums[i] > nums[i - 1])
            {
                length++;
            }
            else
            {
                length = 1;
            }
            result = max(result, length);
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
    vector<int> nums = {1, 3, 5, 4, 7};
    EXPECT_EQ(solution.findLengthOfLCIS(nums), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 2, 2, 2, 2};
    EXPECT_EQ(solution.findLengthOfLCIS(nums), 1);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int result = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
            }
            else
            {
                result = max(result, count);
                count = 0;
            }
        }
        return max(result, count);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    EXPECT_EQ(solution.findMaxConsecutiveOnes(nums), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 0, 1, 1, 0, 1};
    EXPECT_EQ(solution.findMaxConsecutiveOnes(nums), 2);
}
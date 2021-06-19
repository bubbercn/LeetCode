#pragma once
#include "Common.h"

class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        int result = 0;
        constexpr int limit = sizeof(int) * 8;
        for (int i = 0; i < limit; i++)
        {
            int temp = 1 << i;
            int numOf1 = 0;
            for (auto num : nums)
            {
                if ((temp & num) != 0)
                {
                    numOf1++;
                }
            }
            result += numOf1 * (nums.size() - numOf1);
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
    vector<int> nums = {4, 14, 2};
    EXPECT_EQ(solution.totalHammingDistance(nums), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {4, 14, 4};
    EXPECT_EQ(solution.totalHammingDistance(nums), 4);
}
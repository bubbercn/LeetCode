#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int index = n - 1;
        vector<int> result(n);
        while (index >= 0)
        {   
            int left2 = nums[left] * nums[left];
            int right2 = nums[right] * nums[right];
            if (left2 > right2)
            {
                result[index--] = left2;
                left++;
            }
            else
            {
                result[index--] = right2;
                right--;
            }
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
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> output = {0, 1, 9, 16, 100};
    EXPECT_EQ(solution.sortedSquares(nums), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {-7, -3, 2, 3, 11};
    vector<int> output = {4, 9, 9, 49, 121};
    EXPECT_EQ(solution.sortedSquares(nums), output);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        while (left < right)
        {
            int middle = (left + right) / 2;
            int count = 0;
            for (int l = 0, r = 0; r < nums.size(); r++)
            {
                while (l < r && nums[r] - nums[l] > middle)
                    l++;
                count += r - l;
            }
            if (count >= k)
                right = middle;
            else
                left = middle + 1;
        }
        return left;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 3, 1};
    EXPECT_EQ(solution.smallestDistancePair(nums, 1), 0);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 1, 1};
    EXPECT_EQ(solution.smallestDistancePair(nums, 2), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 6, 1};
    EXPECT_EQ(solution.smallestDistancePair(nums, 3), 5);
}
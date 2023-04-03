#pragma once
#include "Common.h"

class Solution
{
public:
    int smallestRangeII(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int result = *nums.rbegin() - *nums.begin();
        for (auto middle = nums.begin() + 1; middle != nums.end(); middle++)
        {
            int top = max(*(middle - 1) + k, *(nums.end() - 1) - k);
            int bottom = min(*nums.begin() + k, *middle - k);
            result = min(result, top - bottom);
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
    vector<int> nums = {1};
    EXPECT_EQ(solution.smallestRangeII(nums, 0), 0);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0, 10};
    EXPECT_EQ(solution.smallestRangeII(nums, 2), 6);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 3, 6};
    EXPECT_EQ(solution.smallestRangeII(nums, 3), 3);
}
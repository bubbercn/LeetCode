#pragma once
#include "Common.h"

class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {
        int min = numeric_limits<int>::max();
        int max = numeric_limits<int>::min();
        for (auto num : nums)
        {
            min = ::min(min, num);
            max = ::max(max, num);
        }
        int result = max - min - 2 * k;
        return result > 0 ? result : 0;
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
    EXPECT_EQ(solution.smallestRangeI(nums, 0), 0);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0, 10};
    EXPECT_EQ(solution.smallestRangeI(nums, 2), 6);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 3, 6};
    EXPECT_EQ(solution.smallestRangeI(nums, 3), 0);
}
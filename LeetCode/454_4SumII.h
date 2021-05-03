#pragma once
#include "Common.h"

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> num1 = {1, 2}, num2 = {-2, -1}, num3 = {-1, 2}, num4 = {0, 2};
    EXPECT_EQ(solution.fourSumCount(num1, num2, num3, num4), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> num1 = {0}, num2 = {0}, num3 = {0}, num4 = {0};
    EXPECT_EQ(solution.fourSumCount(num1, num2, num3, num4), 1);
}

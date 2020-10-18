#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> output = {1, 2};
    EXPECT_EQ(solution.topKFrequent(nums, 2), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1};
    vector<int> output = {1};
    EXPECT_EQ(solution.topKFrequent(nums, 1), output);
}
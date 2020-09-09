#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
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
    vector<int> nums = {5, 2, 6, 1};
    vector<int> output = {2, 1, 1, 0};
    EXPECT_EQ(solution.countSmaller(nums), output);
}

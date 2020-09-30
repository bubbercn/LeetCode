#pragma once
#include "Common.h"

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 5, 1, 1, 6, 4};
    solution.wiggleSort(nums);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 3, 2, 2, 3, 1};
    solution.wiggleSort(nums);
}

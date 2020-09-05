#pragma once
#include "Common.h"

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
    }

    void update(int i, int val)
    {
    }

    int sumRange(int i, int j)
    {
    }
};

class Solution
{
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 3, 5};
    unique_ptr<NumArray> obj(new NumArray(nums));

    EXPECT_EQ(obj->sumRange(0, 2), 9);
    obj->update(1, 2);
    EXPECT_EQ(obj->sumRange(0, 2), 8);
}
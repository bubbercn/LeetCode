#pragma once
#include "Common.h"

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
    }

    int sumRange(int i, int j)
    {
        return 0;
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
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    unique_ptr<NumArray> obj(new NumArray(nums));

    EXPECT_EQ(obj->sumRange(0, 2), 1);
    EXPECT_EQ(obj->sumRange(2, 5), -1);
    EXPECT_EQ(obj->sumRange(0, 5), -3);
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

#pragma once
#include "Common.h"

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        lookup.resize(nums.size());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            lookup[i] = sum;
        }
    }

    int sumRange(int i, int j)
    {
        return i == 0 ? lookup[j] : lookup[j] - lookup[i - 1];
    }

private:
    vector<int> lookup;
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
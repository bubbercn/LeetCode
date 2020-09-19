#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        map<int, int> lookup;
        vector<int> result(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            lookup[nums[i]]++;
            if (i != nums.size() - 1)
            {
                int sum = 0;
                auto end = lookup.find(nums[i]);
                for (auto it = lookup.begin(); it != end; it++)
                {
                    sum += it->second;
                }
                result[i] = sum;
            }
        }
        return result;
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

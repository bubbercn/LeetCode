#pragma once
#include "Common.h"

class Solution
{
public:
    int countTriplets(vector<int> &nums)
    {
        unordered_map<int, int> lookup;
        for (auto i : nums)
        {
            for (auto j : nums)
            {
                lookup[i & j]++;
            }
        }
        int result = 0;
        for (auto k : nums)
        {
            for (auto [ij, count] : lookup)
            {
                if ((k & ij) == 0)
                {
                    result += count;
                }
            }
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
    vector<int> nums = {2, 1, 3};
    EXPECT_EQ(solution.countTriplets(nums), 12);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0, 0, 0};
    EXPECT_EQ(solution.countTriplets(nums), 27);
}
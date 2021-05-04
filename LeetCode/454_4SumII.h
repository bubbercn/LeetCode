#pragma once
#include "Common.h"

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int result = 0;
        unordered_map<int, int> lookup;
        for (auto num3 : nums3)
        {
            for (auto num4 : nums4)
            {
                lookup[num3 + num4]++;
            }
        }
        for (auto num1 : nums1)
        {
            for (auto num2 : nums2)
            {
                if (auto i = lookup.find(-num1 - num2); i != lookup.end())
                {
                    result += i->second;
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
    vector<int> num1 = {1, 2}, num2 = {-2, -1}, num3 = {-1, 2}, num4 = {0, 2};
    EXPECT_EQ(solution.fourSumCount(num1, num2, num3, num4), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> num1 = {0}, num2 = {0}, num3 = {0}, num4 = {0};
    EXPECT_EQ(solution.fourSumCount(num1, num2, num3, num4), 1);
}

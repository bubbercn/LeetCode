#pragma once
#include "Common.h"

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, bool> lookup;
        for (auto num : nums)
        {
            if (auto [it, inserted] = lookup.emplace(num, false); !inserted)
            {
                it->second = true;
            }
        }
        unordered_set<int> result;
        for (auto num : nums)
        {
            if (auto it = lookup.find(num + k); it != lookup.end())
            {
                if (k == 0 && !it->second)
                    continue;
                result.emplace(num);
            }
            if (k != 0)
            {
                if (auto it = lookup.find(num - k); it != lookup.end())
                {
                    result.emplace(num - k);
                }
            }
        }
        return result.size();
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {3, 1, 4, 1, 5};
    EXPECT_EQ(solution.findPairs(nums, 2), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(solution.findPairs(nums, 1), 4);
}
TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 3, 1, 5, 4};
    EXPECT_EQ(solution.findPairs(nums, 0), 1);
}
TEST_F(LeetCodeTest, Example4)
{
    vector<int> nums = {1, 2, 4, 4, 3, 3, 0, 9, 2, 3};
    EXPECT_EQ(solution.findPairs(nums, 3), 2);
}
TEST_F(LeetCodeTest, Example5)
{
    vector<int> nums = {-1, -2, -3};
    EXPECT_EQ(solution.findPairs(nums, 1), 2);
}

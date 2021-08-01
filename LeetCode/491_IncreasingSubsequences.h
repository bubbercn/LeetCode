#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        auto result = helper(nums, nums.begin(), nums.end());
        return {result.begin(), result.end()};
    }
    set<vector<int>> helper(const vector<int> &nums, vector<int>::const_iterator begin, vector<int>::const_iterator end)
    {
        if (nums.size() == 1)
            return {};

        if (distance(begin, end) == 1)
        {
            return {{*begin}};
        }

        set<vector<int>> next = helper(nums, begin + 1, end);
        set<vector<int>> result;
        bool hasDuplicate = false;
        for (auto &v : next)
        {
            if (nums.begin() != begin || v.size() > 1)
            {
                result.emplace(v);
            }
            if (*begin <= v[0])
            {
                if (*begin == v[0])
                    hasDuplicate = true;
                vector<int> temp = {*begin};
                temp.insert(temp.end(), v.begin(), v.end());
                result.emplace(temp);
            }
        }
        if (!hasDuplicate && nums.begin() != begin)
        {
            result.insert({*begin});
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
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> output = {
        {4, 6},
        {4, 6, 7},
        {4, 6, 7, 7},
        {4, 7},
        {4, 7, 7},
        {6, 7},
        {6, 7, 7},
        {7, 7},
    };
    EXPECT_EQ(solution.findSubsequences(nums), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {4, 4, 3, 2, 1};
    vector<vector<int>> output = {
        {4, 4},
    };
    EXPECT_EQ(solution.findSubsequences(nums), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 1, 1};
    vector<vector<int>> output = {
        {1, 1},
        {1, 1, 1}};
    EXPECT_EQ(solution.findSubsequences(nums), output);
}
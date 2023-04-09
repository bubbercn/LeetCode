#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        helper(nums.begin(), nums.end());
        return nums;
    }

private:
    void helper(vector<int>::iterator begin, vector<int>::iterator end)
    {
        if (begin == end or begin + 1 == end)
            return;

        auto middle = begin + (end - begin) / 2;
        swap(*begin, *middle);
        int target = *begin;
        auto left = begin + 1;
        for (auto it = left; it != end; it++)
        {
            if (*it < target)
            {
                swap(*it, *left++);
            }
        }
        swap(*begin, *(--left));
        auto right = end - 1;
        for (auto it = left; it <= right;)
        {
            if (*it > target)
            {
                swap(*it, *right--);
            }
            else
            {
                it++;
            }
        }
        helper(begin, left);
        helper(right + 1, end);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {5, 2, 3, 1};
    vector<int> output = {1, 2, 3, 5};
    EXPECT_EQ(solution.sortArray(nums), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {5, 1, 1, 2, 0, 0};
    vector<int> output = {0, 0, 1, 1, 2, 5};
    EXPECT_EQ(solution.sortArray(nums), output);
}

TEST_F(LeetCodeTest, Case1)
{
    vector<int> nums = {1, 1, 1, 1, 1};
    vector<int> output = {1, 1, 1, 1, 1};
    EXPECT_EQ(solution.sortArray(nums), output);
}
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
        int target = *begin;
        auto left = begin;
        auto right = end - 1;
        while (left < right)
        {
            while (*left < target)
                left++;
            while (*right > target)
                right--;
            if (left < right)
                swap(*left, *right);
        }
        swap(*begin, *middle);
        helper(begin, middle);
        helper(middle + 1, end);
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
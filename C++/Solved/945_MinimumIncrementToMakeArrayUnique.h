#pragma once
#include "Common.h"

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int pre = nums[0];
        queue<int> q;
        int result = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            while (!q.empty() and pre + 1 < nums[i])
            {
                pre++;
                result += pre - q.front();
                q.pop();
            }
            if (nums[i] > pre)
            {
                pre = nums[i];
            }
            else
            {
                q.emplace(nums[i]);
            }
        }
        while (!q.empty())
        {
            result += pre - q.front() + 1;
            pre++;
            q.pop();
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
    vector<int> nums = {1, 2, 2};
    EXPECT_EQ(solution.minIncrementForUnique(nums), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {3, 2, 1, 2, 1, 7};
    EXPECT_EQ(solution.minIncrementForUnique(nums), 6);
}
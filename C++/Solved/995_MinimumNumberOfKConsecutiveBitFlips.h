#pragma once
#include "Common.h"

class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int n = nums.size();
        int result = 0;
        queue<int> q;
        for (int i = 0; i <= n - k; i++)
        {
            if (!q.empty() and i - q.front() >= k)
                q.pop();
            
            if ((q.size() + nums[i]) % 2 == 0)
            {
                result++;
                q.emplace(i);
            }
        }
        for (int i = n - k + 1; i < n; i++)
        {
            if (!q.empty() and i - q.front() >= k)
                q.pop();
            
            if ((q.size() + nums[i]) % 2 == 0)
            {
                return -1;
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
    vector<int> nums = {0, 1, 0};
    EXPECT_EQ(solution.minKBitFlips(nums, 1), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 1, 0};
    EXPECT_EQ(solution.minKBitFlips(nums, 2), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {0, 0, 0, 1, 0, 1, 1, 0};
    EXPECT_EQ(solution.minKBitFlips(nums, 3), 3);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long> preSums(n + 1);
        for (int i = 1; i <= n; i++)
        {
            preSums[i] = preSums[i - 1] + nums[i - 1];
        }
        deque<int> leftList = {0};
        int result = numeric_limits<int>::max();
        for (int i = 1; i <= n; i++)
        {
            while (!leftList.empty() && preSums[i] - preSums[leftList.front()] >= k)
            {
                result = min(result, i - leftList.front());
                leftList.pop_front();
            }

            while (!leftList.empty() && preSums[*leftList.rbegin()] >= preSums[i])
            {
                leftList.pop_back();
            }
            leftList.emplace_back(i);
        }
        return result == numeric_limits<int>::max() ? -1 : result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1};
    EXPECT_EQ(solution.shortestSubarray(nums, 1), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2};
    EXPECT_EQ(solution.shortestSubarray(nums, 4), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {2, -1, 2};
    EXPECT_EQ(solution.shortestSubarray(nums, 3), 3);
}
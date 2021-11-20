#pragma once
#include "Common.h"

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int start = 0, end = 1;
        int result = 0;
        while (end < nums.size())
        {
            int left = nums[start];
            int right = nums[end];

            if (left == right)
            {
                end++;
            }
            else if (left + 1 == right)
            {
                result = max(result, end - start + 1);
                end++;
            }
            else
            {
                start++;
                if (start == end)
                    end++;
            }
        }
        return result;;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    EXPECT_EQ(solution.findLHS(nums), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(solution.findLHS(nums), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 1, 1, 1};
    EXPECT_EQ(solution.findLHS(nums), 0);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {1, 2, 2, 3, 4, 5, 1, 1, 1, 1};
    EXPECT_EQ(solution.findLHS(nums), 7);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> nums = {1, 4, 1, 3, 1, -14, 1, -13};
    EXPECT_EQ(solution.findLHS(nums), 2);
}

TEST_F(LeetCodeTest, Failure3)
{
    vector<int> nums = {1, 2, 2, 1};
    EXPECT_EQ(solution.findLHS(nums), 4);
}
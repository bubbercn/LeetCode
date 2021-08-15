#pragma once
#include "Common.h"

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        vector<int> leftMin(nums.size(), 0);

        {
            int curMin = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (i == 0)
                {
                    curMin = nums[0];
                    leftMin[0] = curMin;
                }
                else
                {
                    leftMin[i] = curMin < nums[i] ? curMin : nums[i];
                    curMin = min(curMin, nums[i]);
                }
            }
        }

        {
            stack<int> lookup;
            int maxRight = numeric_limits<int>::min();
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                while (!lookup.empty() && lookup.top() < nums[i])
                {
                    maxRight = max(lookup.top(), maxRight);
                    lookup.pop();
                }
                if (leftMin[i] != nums[i] && maxRight > leftMin[i])
                {
                    return true;
                }
                if (nums[i] > maxRight)
                {
                    lookup.emplace(nums[i]);
                }
            }
        }

        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(solution.find132pattern(nums), false);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {3, 1, 4, 2};
    EXPECT_EQ(solution.find132pattern(nums), true);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {-1, 3, 2, 0};
    EXPECT_EQ(solution.find132pattern(nums), true);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {1, 3, 2, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(solution.find132pattern(nums), true);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> nums = {3, 5, 0, 3, 4};
    EXPECT_EQ(solution.find132pattern(nums), true);
}
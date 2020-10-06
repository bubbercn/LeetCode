#pragma once
#include "Common.h"

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int num1 = INT_MAX, num2 = INT_MAX;
        for (auto num : nums)
        {
            if (num < num1)
            {
                num1 = num;
            }
            else if (num > num1 && num < num2)
            {
                num2 = num;
            }
            else if (num > num2)
            {
                return true;
            }
        }
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(solution.increasingTriplet(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {5, 4, 3, 2, 1};
    EXPECT_EQ(solution.increasingTriplet(nums), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {1, 0, 0, 10, 0, 0, 100000000};
    EXPECT_EQ(solution.increasingTriplet(nums), true);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> nums = {1, 1, -2, 6};
    EXPECT_EQ(solution.increasingTriplet(nums), false);
}
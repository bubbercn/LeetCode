#pragma once
#include "Common.h"

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int n = *max_element(nums.begin(), nums.end());
        n++;
        vector<int> sumVector(n, 0);
        for (auto num : nums)
        {
            sumVector[num] += num;
        }

        int value0 = 0;
        int value1 = sumVector[0];
        for (int i = 1; i < n; i++)
        {
            int nextValue0 = max(value0, value1);
            value1 = sumVector[i] + value0;
            value0 = nextValue0;
        }
        return max(value0, value1);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {3, 4, 2};
    EXPECT_EQ(solution.deleteAndEarn(nums), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    EXPECT_EQ(solution.deleteAndEarn(nums), 9);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {3, 1};
    EXPECT_EQ(solution.deleteAndEarn(nums), 4);
}

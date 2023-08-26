#pragma once
#include "Common.h"

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int min = *min_element(nums.begin(), nums.end());
        int result = 0;
        for_each(nums.begin(), nums.end(), [&](int n) {
            result += n - min;
        });
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
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(solution.minMoves(nums), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 1, 1};
    EXPECT_EQ(solution.minMoves(nums), 0);
}
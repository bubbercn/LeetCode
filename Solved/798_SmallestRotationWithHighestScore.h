#pragma once
#include "Common.h"

class Solution
{
public:
    int bestRotation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> diffs(n);
        for (int i = 0; i < n; i++)
        {
            int low = (i + 1) % n;
            int high = (i - nums[i] + n + 1) % n;
            diffs[low]++;
            diffs[high]--;
            if (low >= high)
            {
                diffs[0]++;
            }
        }
        int result = 0;
        int max = 0;
        int score = 0;
        for (int i = 0; i < n; i++)
        {
            score += diffs[i];
            if (score > max)
            {
                result = i;
                max = score;
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
    vector<int> nums = {2, 3, 1, 4, 0};
    EXPECT_EQ(solution.bestRotation(nums), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 3, 0, 2, 4};
    EXPECT_EQ(solution.bestRotation(nums), 0);
}
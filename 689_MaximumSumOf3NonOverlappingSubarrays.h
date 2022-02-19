#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int sum1 = accumulate(nums.begin(), nums.begin() + k, 0);
        int sum2 = accumulate(nums.begin() + k, nums.begin() + 2 * k, 0);
        int sum3 = accumulate(nums.begin() + 2 * k, nums.begin() + 3 * k, 0);
        vector<vector<int>> indexes = {3, vector<int>()};
        int n = nums.size() - 3 * k;
        int max1, max2, max3;
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
            {
                max1 = sum1;
                max2 = max1 + sum2;
                max3 = max2 + sum3;
                indexes[0].assign({0});
                indexes[1].assign({0, k});
                indexes[2].assign({0, k, 2 * k});
            }
            else
            {
                sum1 -= nums[i - 1];
                sum1 += nums[i + k - 1];
                sum2 -= nums[i + k - 1];
                sum2 += nums[i + 2 * k - 1];
                sum3 -= nums[i + 2 * k - 1];
                sum3 += nums[i + 3 * k - 1];
                if (sum1 > max1)
                {
                    max1 = sum1;
                    indexes[0][0] = i;
                }
                if (max1 + sum2 > max2)
                {
                    max2 = max1 + sum2;
                    indexes[1][0] = indexes[0][0];
                    indexes[1][1] = i + k;
                }
                if (max2 + sum3 > max3)
                {
                    max3 = max2 + sum3;
                    indexes[2][0] = indexes[1][0];
                    indexes[2][1] = indexes[1][1];
                    indexes[2][2] = i + 2 * k;
                }
            }
        }
        return indexes[2];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 2, 1, 2, 6, 7, 5, 1};
    vector<int> output = {0, 3, 5};
    EXPECT_EQ(solution.maxSumOfThreeSubarrays(nums, 2), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 1, 2, 1, 2, 1, 2, 1};
    vector<int> output = {0, 2, 4};
    EXPECT_EQ(solution.maxSumOfThreeSubarrays(nums, 2), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {7, 13, 20, 19, 19, 2, 10, 1, 1, 19};
    vector<int> output = {1, 4, 7};
    EXPECT_EQ(solution.maxSumOfThreeSubarrays(nums, 3), output);
}

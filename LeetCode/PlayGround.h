#pragma once
#include "Common.h"

class Solution
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {
        vector<vector<int>> mins(nums.size(), vector<int>(nums.size(), 0));
        vector<vector<long>> sums(nums.size(), vector<long>(nums.size(), 0));
        long result = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = 0; j < nums.size() - i; j++)
            {
                if (j == i + j)
                {
                    sums[j][j] = nums[i];
                    mins[j][j] = nums[j];
                    result = sums[j][j] * mins[j][j];
                }
                else
                {
                    sums[j][i + j] = sums[j][i + j - 1] + sums[i + j][i + j];
                    mins[j][i + j] = min(mins[j][i + j - 1], mins[i + j][i + j]);
                    result = max(result, sums[j][i + j] * mins[j][i + j]);
                }
            }
        }
        return result % limit;
    }

private:
    inline static constexpr int limit = 1000000000 + 7;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 2, 3, 2};
    EXPECT_EQ(solution.maxSumMinProduct(nums), 14);
}

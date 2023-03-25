#pragma once
#include "Common.h"

class Solution
{
public:
    int sumSubseqWidths(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> lookup(n);
        lookup[0] = 1;
        for (int i = 1; i < n; i++)
        {
            lookup[i] = lookup[i - 1] * 2;
            lookup[i] %= MOD;
        }
        long result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            result += static_cast<long>(nums[i]) * (lookup[i] - lookup[n - 1 - i]);
            result %= MOD;
        }
        return result;
    }

private:
    static constexpr int MOD = 1000000000 + 7;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {2, 1, 3};
    EXPECT_EQ(solution.sumSubseqWidths(nums), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2};
    EXPECT_EQ(solution.sumSubseqWidths(nums), 0);
}
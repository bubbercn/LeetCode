#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> result;
        for (int i = 1; i <= 9; i++)
        {
            auto nums = helper(i, n - 1, k);
            int base = i * pow(10, n - 1);
            for (auto num : nums)
            {
                result.emplace_back(base + num);
            }
        }
        return result;
    }

private:
    vector<int> helper(int pre, int n, int k)
    {
        if (n == 0)
            return {0};

        set<int> digits;
        digits.emplace(pre - k);
        digits.emplace(pre + k);
        vector<int> result;
        for (auto d : digits)
        {
            if (d >= 0 and d <= 9)
            {
                int base = d * pow(10, n - 1);
                auto nums = helper(d, n - 1, k);
                for (auto num : nums)
                {
                    result.emplace_back(base + num);
                }
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
    vector<int> output = {181, 292, 707, 818, 929};
    EXPECT_EQ(solution.numsSameConsecDiff(3, 7), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98};
    EXPECT_EQ(solution.numsSameConsecDiff(2, 1), output);
}
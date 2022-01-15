#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> result(n);
        result[0] = 1;
        int sign = 1;
        int offset = n - 1;
        for (int i = 1; i < k; i++)
        {
            result[i] = result[i - 1] + (offset--) * sign;
            sign = -sign;
        }
        for (int i = k; i < n; i++)
        {
            result[i] = result[i - 1] + sign;
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
    vector<int> output = {1, 2, 3};
    EXPECT_EQ(solution.constructArray(3, 1), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {1, 3, 2};
    EXPECT_EQ(solution.constructArray(3, 2), output);
}
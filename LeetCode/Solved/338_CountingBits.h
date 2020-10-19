#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> result(num + 1);
        result[0] = 0;
        int offset = 1;
        for (int i = 1; i <= num; i++)
        {
            if (i == offset * 2)
            {
                offset *= 2;
            }
            result[i] = result[i - offset] + 1;
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> output = {0, 1, 1};
    EXPECT_EQ(solution.countBits(2), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {0, 1, 1, 2, 1, 2};
    EXPECT_EQ(solution.countBits(5), output);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &A)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> A = {1, 2, 3, 4};
    EXPECT_EQ(solution.numberOfArithmeticSlices(A), 3);
}
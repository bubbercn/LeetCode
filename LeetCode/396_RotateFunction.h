#pragma once
#include "Common.h"

class Solution
{
public:
    int maxRotateFunction(vector<int> &A)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
    inline static vector<int> A;
};

TEST_F(LeetCodeTest, Example1)
{
    A = {4, 3, 2, 6};
    EXPECT_EQ(solution.maxRotateFunction(A), 26);
}

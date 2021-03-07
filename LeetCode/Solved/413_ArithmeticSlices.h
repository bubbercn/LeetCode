#pragma once
#include "Common.h"

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &A)
    {
        int result = 0;
        int previousCount = 0;
        for (int i = 0; i < A.size(); i++)
        {
            int currentCount = 0;
            if (i - 2 >= 0 && A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                currentCount = ++previousCount;
            result += currentCount;
            previousCount = currentCount;
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
    vector<int> A = {1, 2, 3, 4};
    EXPECT_EQ(solution.numberOfArithmeticSlices(A), 3);
}

TEST_F(LeetCodeTest, Case1)
{
    vector<int> A = {1, 2, 3, 4, 6};
    EXPECT_EQ(solution.numberOfArithmeticSlices(A), 3);
}
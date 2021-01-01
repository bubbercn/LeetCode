#pragma once
#include "Common.h"

class Solution
{
public:
    int maxRotateFunction(vector<int> &A)
    {
        if (A.empty())
            return 0;

        long sum = accumulate(A.begin(), A.end(), 0l);
        int result = INT_MIN;
        int current = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < A.size(); j++)
                {
                    current += j * getB(A, j, i);
                }
            }
            else
            {
                current = current - A.size() * getB(A, A.size() - 1, i - 1) + sum;
            }
            result = max(result, current);
        }
        return result;
    }
    int getB(vector<int> &A, int index, int rotate)
    {
        int originalIndex = index - rotate;
        if (originalIndex < 0)
            originalIndex += A.size();
        return A[originalIndex];
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

TEST_F(LeetCodeTest, Failure1)
{
    A = {2147483647, 2147483647};
    EXPECT_EQ(solution.maxRotateFunction(A), 2147483647);
}

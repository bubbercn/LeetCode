#pragma once
#include "Common.h"

class Solution
{
public:
    int maxValue(int n, int index, int maxSum)
    {
        int left = 1;
        int right = maxSum;
        long leftCount = index;
        long rightCount = n - index - 1;
        auto helper = [&](long value) {
            long sum = value;
            int count = min(leftCount, value - 1);
            sum += (value - 1 + value - 1 - count + 1) * count / 2;
            sum += leftCount > value - 1 ? leftCount - value + 1 : 0;
            count = min(rightCount, value - 1);
            sum += (value - 1 + value - 1 - count + 1) * count / 2;
            sum += rightCount > value - 1 ? rightCount - value + 1 : 0;
            return sum;
        };
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (helper(middle) > maxSum)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return right;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.maxValue(4, 2, 6), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.maxValue(6, 1, 10), 3);
}

// TEST_F(LeetCodeTest, Example3)
// {
//     EXPECT_EQ(solution.areAlmostEqual("kelb", "kelb"), true);
// }

// TEST_F(LeetCodeTest, Example4)
// {
//     EXPECT_EQ(solution.areAlmostEqual("abcd", "dcba"), false);
// }

TEST_F(LeetCodeTest, Faulre1)
{
    EXPECT_EQ(solution.maxValue(3, 2, 18), 7);
}

TEST_F(LeetCodeTest, Faulre2)
{
    EXPECT_EQ(solution.maxValue(4458197, 897057, 683214517), 26053);
}
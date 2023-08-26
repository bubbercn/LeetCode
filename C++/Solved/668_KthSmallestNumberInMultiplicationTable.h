#pragma once
#include "Common.h"

class Solution
{
public:
    int findKthNumber(int m, int n, int k)
    {
        int left = 1;
        int right = m * n;
        while (left <= right)
        {
            int middle = (left + right) >> 1;
            int temp = check(middle, m, n, k);
            if (temp == 0)
            {
                return middle;
            }
            else if (temp < 0)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return 0;
    }

private:
    int check(int value, int m, int n, int k)
    {
        int small = 0;
        int equal = 0;
        for (int i = 1; i <= m; i++)
        {
            bool exist = (value % i) == 0 && value <= i * n;
            equal += (exist ? 1 : 0);
            small += min(value / i, n) - (exist ? 1 : 0);
        }
        if (small >= k)
            return -1;

        if (small + equal >= k)
            return 0;

        return 1;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.findKthNumber(3, 3, 5), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findKthNumber(2, 3, 6), 6);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int preimageSizeFZF(int k)
    {
        return binarySearch(k) ? 5 : 0;
    }

    bool binarySearch(int k)
    {
        size_t left = 0, right = 5l * k;
        while (left <= right)
        {
            size_t mid = left + (right - left) / 2;
            int temp = countZeroes(mid);
            if (temp == k)
                return true;
            else if (temp < k)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }

    int countZeroes(size_t n)
    {
        int result = 0;
        while (n)
        {
            result += n / 5;
            n /= 5;
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
    EXPECT_EQ(solution.preimageSizeFZF(0), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.preimageSizeFZF(5), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.preimageSizeFZF(3), 5);
}

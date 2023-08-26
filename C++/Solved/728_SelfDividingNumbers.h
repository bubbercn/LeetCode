#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> result;
        for (int i = left; i <= right; i++)
        {
            if (isSelfDividingNumber(i))
                result.emplace_back(i);
        }
        return result;
    }

private:
    bool isSelfDividingNumber(int num)
    {
        int n = num;
        while (n > 0)
        {
            int digit = n % 10;
            if (digit == 0)
                return false;
            if (num % digit)
                return false;
            n /= 10;
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> output = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
    EXPECT_EQ(solution.selfDividingNumbers(1, 22), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {48, 55, 66, 77};
    EXPECT_EQ(solution.selfDividingNumbers(47, 85), output);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    string convertToBase7(int num)
    {
        bool negative = false;
        if (num < 0)
        {
            num = -num;
            negative = true;
        }
        list<char> result;
        while (num > 0)
        {
            int r = num % 7;
            result.emplace_front('0' + r);
            num /= 7;
        }
        if (result.empty())
            result.emplace_back('0');
        if (negative)
            result.emplace_front('-');
        return {result.begin(), result.end()};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.convertToBase7(100), "202");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.convertToBase7(-7), "-10");
}
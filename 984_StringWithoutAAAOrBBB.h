#pragma once
#include "Common.h"

class Solution
{
public:
    string strWithout3a3b(int a, int b)
    {
        list<char> result;
        char c = a >= b ? 'a' : 'b';
        while (a > 0 and b > 0)
        {
            result.emplace_back(c);
            if (c == 'a')
            {
                a--;
                c = 'b';
            }
            else
            {
                b--;
                c = 'a';
            }
        }
        result.emplace_back(c);
        if (c == 'a')
        {
            a--;
        }
        else
        {
            b--;
        }

        int left = a > 0 ? a : b;
        c = a > 0 ? 'a' : 'b';
        for (auto it = result.begin(); it != result.end() and left > 0; it++)
        {
            if (*it != c)
            {
                result.insert(it, c);
                left--;
            }
        }
        if (left > 0)
        {
            result.emplace_back(c);
        }
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
    EXPECT_EQ(solution.strWithout3a3b(1, 2), "bab");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.strWithout3a3b(4, 1), "aabaa");
}
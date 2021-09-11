#pragma once
#include "Common.h"

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        bool reverse = true;
        auto reverseString = [&s](int begin, int end)
        {
            while (begin < end)
            {
                swap(s[begin++], s[(end--) - 1]);
            }
        };
        for (int i = 0; i < s.length(); i += k)
        {
            if (reverse)
            {
                reverseString(i, min(i + k, static_cast<int>(s.length())));
            }
            reverse = !reverse;
        }
        return s;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.reverseStr("abcdefg", 2), "bacdfeg");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.reverseStr("abcd", 2), "bacd");
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int uniqueLetterString(string_view s)
    {
        int n= s.length();
        vector<list<int>> pos(26);
        for (int i = 0; i < n; i++)
        {
            pos[s[i] - 'A'].emplace_back(i);
        }
        int result = 0;
        for (auto& posList : pos)
        {
            for (auto it = posList.begin(); it != posList.end(); it++)
            {
                int left = it == posList.begin() ? -1 : *prev(it);
                int right = next(it) == posList.end() ? n : *next(it);
                result += (*it - left) * (right - *it);
            }
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
    EXPECT_EQ(solution.uniqueLetterString("ABC"), 10);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.uniqueLetterString("ABA"), 8);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.uniqueLetterString("LEETCODE"), 92);
}
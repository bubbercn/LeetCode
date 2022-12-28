#pragma once
#include "Common.h"

class Solution
{
public:
    string shiftingLetters(string_view s, vector<int> &shifts)
    {
        int n = s.length();
        string result;
        result.resize(n);
        int shift = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            shift += shifts[i];
            shift %= 26;
            result[i] = (s[i] - 'a' + shift) % 26 + 'a';
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
    vector<int> shifts = {3, 5, 9};
    EXPECT_EQ(solution.shiftingLetters("abc", shifts), "rpl");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> shifts = {1, 2, 3};
    EXPECT_EQ(solution.shiftingLetters("aaa", shifts), "gfd");
}
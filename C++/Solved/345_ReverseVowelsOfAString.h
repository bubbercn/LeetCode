#pragma once
#include "Common.h"

class Solution
{
public:
    string reverseVowels(string s)
    {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        long pos1 = 0;
        long pos2 = s.length() - 1;
        while (pos1 < pos2)
        {
            if (vowels.count(s[pos1]) == 0)
            {
                pos1++;
                continue;
            }
            if (vowels.count(s[pos2]) == 0)
            {
                pos2--;
                continue;
            }
            swap(s[pos1++], s[pos2--]);
        }
        return s;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.reverseVowels("hello"), "holle");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.reverseVowels("leetcode"), "leotcede");
}

TEST_F(LeetCodeTest, EmptryString)
{
    EXPECT_EQ(solution.reverseVowels(""), "");
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.reverseVowels("aA"), "Aa");
}

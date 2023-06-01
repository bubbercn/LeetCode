#pragma once
#include "Common.h"

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string_view order)
    {
        for (auto i = 0; i < order.size(); i++)
        {
            asc[order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); i++)
        {
            if (isGreater(words[i - 1], words[i]))
                return false;
        }
        return true;
    }

private:
    vector<int> asc = vector<int>(26);
    bool isGreater(string_view s1, string_view s2)
    {
        int i1 = 0;
        int i2 = 0;
        while (i1 < s1.length() and i2 < s2.length())
        {
            if (s1[i1] == s2[i2])
            {
                i1++;
                i2++;
                continue;
            }
            return asc[s1[i1] - 'a'] > asc[s2[i2] - 'a'];
        }
        return i1 < s1.length();
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> words = {"hello", "leetcode"};
    EXPECT_EQ(solution.isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"word", "world", "row"};
    EXPECT_EQ(solution.isAlienSorted(words, "worldabcefghijkmnpqstuvxyz"), false);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> words = {"apple", "app"};
    EXPECT_EQ(solution.isAlienSorted(words, "abcdefghijklmnopqrstuvwxyz"), false);
}
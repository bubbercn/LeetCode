#pragma once
#include "Common.h"

class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &words)
    {
        unordered_set<string> result;
        for (auto &word : words)
        {
            string pattern = getPattern(word);
            result.emplace(pattern);
        }
        return result.size();
    }

private:
    string getPattern(string_view word)
    {
        string s1;
        string s2;
        for (int i = 0; i < word.length(); i++)
        {
            if (i % 2 == 0)
            {
                s1 += word[i];
            }
            else
            {
                s2 += word[i];
            }
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 + s2;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> words = {"abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx"};
    EXPECT_EQ(solution.numSpecialEquivGroups(words), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"abc", "acb", "bac", "bca", "cab", "cba"};
    EXPECT_EQ(solution.numSpecialEquivGroups(words), 3);
}

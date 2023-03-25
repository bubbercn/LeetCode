#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string_view pattern)
    {
        vector<string> result;
        for (auto &word : words)
        {
            if (match(word, pattern))
                result.emplace_back(word);
        }
        return result;
    }

private:
    bool match(string_view word, string_view pattern)
    {
        unordered_map<char, char> lookup1;
        unordered_map<char, char> lookup2;
        for (int i = 0; i < word.length(); i++)
        {
            if (!check(lookup1, word[i], pattern[i]))
                return false;
            if (!check(lookup2, pattern[i], word[i]))
                return false;
        }
        return true;
    }

private:
    bool check(unordered_map<char, char> &lookup, char a, char b)
    {
        if (auto it = lookup.find(a); it != lookup.end())
        {
            if (b != it->second)
                return false;
        }
        else
        {
            lookup.emplace(a, b);
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
    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    vector<string> output = {"mee", "aqq"};
    EXPECT_EQ(solution.findAndReplacePattern(words, "abb"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"a", "b", "c"};
    vector<string> output = {"a", "b", "c"};
    EXPECT_EQ(solution.findAndReplacePattern(words, "a"), output);
}
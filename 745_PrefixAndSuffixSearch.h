#pragma once
#include "Common.h"

class WordFilter
{
public:
    WordFilter(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            string &word = words[i];
            int n = word.length();
            for (int j = 0; j < n; j++)
            {
                if (auto [it, inserted] = lookup[word.substr(j, n - j)].emplace(word, i); !inserted)
                {
                    if (i > it->second)
                    {
                        it->second = i;
                    }
                }
            }
        }
    }

    int f(string prefix, string suffix)
    {
        auto &rs = lookup[suffix];
        int result = -1;
        for (auto &[word, index] : rs)
        {
            if (word.length() < prefix.length())
                continue;
            if (word.substr(0, prefix.length()) == prefix)
                result = max(result, index);
        }
        return result;
    }

private:
    unordered_map<string, unordered_map<string, int>> lookup;
};

class Solution
{
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> words = {"apple"};
    WordFilter wordFilter(words);
    EXPECT_EQ(wordFilter.f("a", "e"), 0);
}
#pragma once
#include "Common.h"

char replaceVowels(char c)
{
    const static unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    if (vowels.count(c) == 0)
        return c;
    return '#';
}

class Solution
{
public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        unordered_set<string> lookup1;
        unordered_map<string, string> lookup2;
        unordered_map<string, string> lookup3;
        for (auto &word : wordlist)
        {
            lookup1.emplace(word);
            string temp = word;
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            lookup2.emplace(temp, word);
            transform(temp.begin(), temp.end(), temp.begin(), replaceVowels);
            lookup3.emplace(temp, word);
        }
        vector<string> result;
        for (auto &query : queries)
        {
            if (auto it = lookup1.find(query); it != lookup1.end())
            {
                result.emplace_back(query);
                continue;
            }
            transform(query.begin(), query.end(), query.begin(), ::tolower);
            if (auto it = lookup2.find(query); it != lookup2.end())
            {
                result.emplace_back(it->second);
                continue;
            }
            transform(query.begin(), query.end(), query.begin(), replaceVowels);
            if (auto it = lookup3.find(query); it != lookup3.end())
            {
                result.emplace_back(it->second);
            }
            else
            {
                result.emplace_back("");
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
    vector<string> wordlist = {"KiTe", "kite", "hare", "Hare"};
    vector<string> queries = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};
    vector<string> output = {"kite", "KiTe", "KiTe", "Hare", "hare", "", "", "KiTe", "", "KiTe"};
    EXPECT_EQ(solution.spellchecker(wordlist, queries), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> wordlist = {"yellow"};
    vector<string> queries = {"YellOw"};
    vector<string> output = {"yellow"};
    EXPECT_EQ(solution.spellchecker(wordlist, queries), output);
}
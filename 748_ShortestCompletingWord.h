#pragma once
#include "Common.h"

class Solution
{
public:
    string shortestCompletingWord(string_view licensePlate, vector<string> &words)
    {
        unordered_map<char, int> pattern;
        for (auto c : licensePlate)
        {
            if (c >= 'a' && c <= 'z')
            {
                pattern[c]++;
            }
            else if (c >= 'A' && c <= 'Z')
            {
                pattern[c - 'A' + 'a']++;
            }
        }
        string result;
        int resultLength = numeric_limits<int>::max();
        for (int i = 0; i < words.size(); i++)
        {
            auto temp = pattern;
            string &word = words[i];
            for (auto c : word)
            {
                if (auto it = temp.find(c); it != temp.end())
                {
                    it->second--;
                    if (it->second == 0)
                        temp.erase(c);
                }
            }
            if (temp.empty() && word.length() < resultLength)
            {
                result = word;
                resultLength = word.length();
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
    vector<string> words = {"step", "steps", "stripe", "stepple"};
    EXPECT_EQ(solution.shortestCompletingWord("1s3 PSt", words), "steps");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"looks", "pest", "stew", "show"};
    EXPECT_EQ(solution.shortestCompletingWord("1s3 45", words), "pest");
}
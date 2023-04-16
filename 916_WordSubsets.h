#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<int> pattern(26, 0);
        for (auto &word : words2)
        {
            auto temp = getPattern(word);
            for (int i = 0; i < 26; i++)
            {
                pattern[i] = max(pattern[i], temp[i]);
            }
        }
        vector<string> result;
        for (auto &word : words1)
        {
            auto temp = getPattern(word);
            bool match = true;
            for (int i = 0; i < 26; i++)
            {
                if (temp[i] < pattern[i])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                result.emplace_back(word);
        }
        return result;
    }

private:
    vector<int> getPattern(string_view s)
    {
        vector<int> result(26, 0);
        for (auto c : s)
        {
            result[c - 'a']++;
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
    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2 = {"e", "o"};
    vector<string> output = {"facebook", "google", "leetcode"};
    EXPECT_EQ(solution.wordSubsets(words1, words2), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2 = {"l", "e"};
    vector<string> output = {"apple", "google", "leetcode"};
    EXPECT_EQ(solution.wordSubsets(words1, words2), output);
}
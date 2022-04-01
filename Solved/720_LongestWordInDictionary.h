#pragma once
#include "Common.h"

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end());
        unordered_set<string> wordsSet;
        int maxLength = 0;
        string result;
        for (const auto &word : words)
        {
            int length = word.length();
            if (length == 1 || wordsSet.count(word.substr(0, length - 1)) != 0)
            {
                wordsSet.emplace(word);
                if (length > maxLength)
                {
                    maxLength = length;
                    result = word;
                }
                else if (length == maxLength)
                {
                    result = min(word, result);
                }
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
    vector<string> words = {"w", "wo", "wor", "worl", "world"};
    EXPECT_EQ(solution.longestWord(words), "world");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    EXPECT_EQ(solution.longestWord(words), "apple");
}

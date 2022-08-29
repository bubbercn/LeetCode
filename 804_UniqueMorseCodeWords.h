#pragma once
#include "Common.h"

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> result;
        for (auto &word : words)
        {
            string morseWord = "";
            for (auto &c : word)
            {
                morseWord += morse[c - 'a'];
            }
            result.emplace(morseWord);
        }
        return result.size();
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> words = {"gin", "zen", "gig", "msg"};
    EXPECT_EQ(solution.uniqueMorseRepresentations(words), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"a"};
    EXPECT_EQ(solution.uniqueMorseRepresentations(words), 1);
}

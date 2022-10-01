#pragma once
#include "Common.h"

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &w1, const string &w2)
             { return w1.length() > w2.length(); });
        
        int result = 0;
        unordered_set<string> lookup;
        for (auto& word : words)
        {
            if (!lookup.emplace(word).second)
                continue;
            
            for (int i = 1; i < word.length(); i++)
            {
                lookup.emplace(word.substr(i));
            }

            result += word.length() + 1;
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
    vector<string> words = {"time", "me", "bell"};
    EXPECT_EQ(solution.minimumLengthEncoding(words), 10);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"t"};
    EXPECT_EQ(solution.minimumLengthEncoding(words), 2);
}
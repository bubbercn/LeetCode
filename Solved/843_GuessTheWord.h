#pragma once
#include "Common.h"

// This is the Master's API interface.
// You should not implement it, or speculate about its implementation
class Master
{
public:
    int guess(string word)
    {
        return 0;
    }
};

class Solution
{
public:
    void findSecretWord(vector<string> &words, Master &master)
    {
        srand(time(0));
        unordered_map<string, unordered_map<string, int>> similarityLookup;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sim = getSimilarity(words[i], words[j]);
                similarityLookup[words[i]][words[j]] = sim;
                similarityLookup[words[j]][words[i]] = sim;
            }
        }

        while (!words.empty())
        {
            string guess = words[rand() % words.size()];
            int guessResult = master.guess(guess);
            if (guessResult == 6)
                return;
            vector<string> nextWords;
            for (auto &word : words)
            {
                if (word == guess)
                    continue;

                if (similarityLookup[guess][word] == guessResult)
                    nextWords.emplace_back(word);
            }
            words.swap(nextWords);
        }
    }

private:
    int getSimilarity(string_view s1, string_view s2)
    {
        int result = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == s2[i])
                result++;
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

#pragma once
#include "Common.h"

class Solution
{
public:
    int numMatchingSubseq(string_view s, vector<string> &words)
    {
        vector<vector<int>> wordIndex(26);
        for (int i = 0; i < s.length(); i++)
        {
            wordIndex[s[i] - 'a'].emplace_back(i);
        }
        int result = 0;
        for (auto &word : words)
        {
            int curPos = -1;
            bool match = true;
            for (auto c : word)
            {
                auto &index = wordIndex[c - 'a'];
                if (index.empty())
                {
                    match = false;
                    break;
                }
                else
                {
                    auto it = upper_bound(index.begin(), index.end(), curPos);
                    if (it == index.end())
                    {
                        match = false;
                        break;
                    }
                    else
                    {
                        curPos = *it;
                    }
                }
            }
            if (match)
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

TEST_F(LeetCodeTest, Example1)
{
    vector<string> words = {"a", "bb", "acd", "ace"};
    EXPECT_EQ(solution.numMatchingSubseq("abcde", words), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
    EXPECT_EQ(solution.numMatchingSubseq("dsahjpjauf", words), 2);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        sort(dictionary.begin(), dictionary.end(), [](string_view s1, string_view s2)
             {
                 if (s1.length() > s2.length())
                     return true;
                 if (s1.length() < s2.length())
                     return false;
                 for (int i = 0; i < s1.length(); i++)
                 {
                     if (s1[i] < s2[i])
                         return true;
                     if (s1[i] > s2[i])
                         return false;
                 }
                 return false;
             });

        vector<vector<int>> lookup(26);
        for (int i = 0; i < s.length(); i++)
        {
            lookup[s[i] - 'a'].emplace_back(i);
        }

        for (const auto &word : dictionary)
        {
            if (isSubstring(lookup, word))
                return word;
        }

        return {};
    }

private:
    bool isSubstring(const vector<vector<int>> &lookup, string_view word)
    {
        vector<int> pos(26, 0);
        int curPos = -1;
        for (auto c : word)
        {
            const vector<int> &temp = lookup[c - 'a'];
            if (temp.empty())
                return false;

            bool match = false;
            for (int i = pos[c - 'a']; i < temp.size(); i++)
            {
                if (temp[i] <= curPos)
                    continue;

                pos[c - 'a']++;
                curPos = temp[i];
                match = true;
                break;
            }
            if (!match)
                return false;
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
    vector<string> dictionary = {"ale", "apple", "monkey", "plea"};
    EXPECT_EQ(solution.findLongestWord("abpcplea", dictionary), "apple");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> dictionary = {"a", "b", "c"};
    EXPECT_EQ(solution.findLongestWord("abpcplea", dictionary), "a");
}

TEST_F(LeetCodeTest, Case1)
{
    vector<string> dictionary = {"a", "b", "c"};
    EXPECT_EQ(solution.findLongestWord("d", dictionary), "");
}
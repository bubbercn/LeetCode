#pragma once
#include "Common.h"

class Solution
{
public:
    int expressiveWords(string_view s, vector<string> &words)
    {
        int result = 0;
        auto pattern = extractPattern(s);
        for (auto &word : words)
        {
            auto temp = extractPattern(word);
            if (pattern.size() != temp.size())
                continue;
            bool match = true;
            for (auto it1 = pattern.begin(), it2 = temp.begin(); it1 != pattern.end(); it1++, it2++)
            {
                if (it1->first != it2->first)
                {
                    match = false;
                    break;
                }

                if (it1->second == it2->second)
                    continue;
                
                if (it1->second < it2->second || it1->second < 3)
                    match = false;
            }
            if (match)
                result++;
        }
        return result;
    }

private:
    list<pair<char, int>> extractPattern(string_view s)
    {
        list<pair<char, int>> result;
        char cur = s[0];
        int count = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == cur)
            {
                count++;
            }
            else
            {
                result.emplace_back(cur, count);
                cur = s[i];
                count = 1;
            }
        }
        result.emplace_back(cur, count);
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
    vector<string> words = {"hello", "hi", "helo"};
    EXPECT_EQ(solution.expressiveWords("heeellooo", words), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"zzyy", "zy", "zyy"};
    EXPECT_EQ(solution.expressiveWords("zzzzzyyyyy", words), 3);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<string> words = {"dinnssoo", "ddinso", "ddiinnso", "ddiinnssoo", "ddiinso", "dinsoo", "ddiinsso", "dinssoo", "dinso"};
    EXPECT_EQ(solution.expressiveWords("dddiiiinnssssssoooo", words), 3);
}
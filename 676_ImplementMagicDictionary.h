#pragma once
#include "Common.h"

class MagicDictionary
{
public:
    MagicDictionary()
    {
    }

    void buildDict(const vector<string> &dictionary)
    {
        lookup.clear();
        for (const auto &s : dictionary)
        {
            for (int i = 0; i < s.length(); i++)
            {
                string temp = s.substr(0, i) + "*" + s.substr(i + 1);
                lookup[temp].emplace_back(s);
            }
        }
    }

    bool search(const string &searchWord)
    {
        for (int i = 0; i < searchWord.length(); i++)
        {
            string temp = searchWord.substr(0, i) + "*" + searchWord.substr(i + 1);
            if (auto it = lookup.find(temp); it != lookup.end() && (it->second.size() > 1 || it->second[0] != searchWord))
                return true;
        }
        return false;
    }

private:
    unordered_map<string, vector<string>> lookup;
};

class Solution
{
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    MagicDictionary magicDictionary;
    magicDictionary.buildDict({"hello", "leetcode"});
    EXPECT_FALSE(magicDictionary.search("hello"));
    EXPECT_TRUE(magicDictionary.search("hhllo"));
    EXPECT_FALSE(magicDictionary.search("hell"));
    EXPECT_FALSE(magicDictionary.search("leetcoded"));
}

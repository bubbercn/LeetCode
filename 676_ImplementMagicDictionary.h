#pragma once
#include "Common.h"

class MagicDictionary
{
public:
    MagicDictionary()
    {
    }

    void buildDict(vector<string> dictionary)
    {
    }

    bool search(string searchWord)
    {
        return false;
    }
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

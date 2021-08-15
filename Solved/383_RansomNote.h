#pragma once
#include "Common.h"

class Solution
{
public:
    bool canConstruct(const string& ransomNote, const string& magazine)
    {
        vector<int> lookup(26, 0);
        for (auto c : magazine)
        {
            lookup[c - 'a']++;
        }
        for (auto c : ransomNote)
        {
            lookup[c - 'a']--;
            if (lookup[c - 'a'] < 0)
            {
                return false;
            }
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
    EXPECT_EQ(solution.canConstruct("a", "b"), false);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.canConstruct("aa", "ab"), false);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.canConstruct("aa", "aab"), true);
}
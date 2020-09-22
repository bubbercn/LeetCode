#pragma once
#include "Common.h"

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        unordered_map<char, int> lookup;
        for (auto c : s)
        {
            lookup[c]++;
        }

        unordered_set<char> used;
        list<char> charStack;
        for (auto c : s)
        {
            lookup[c]--;

            if (used.find(c) != used.end())
            {
                continue;
            }

            while (!charStack.empty() && c < charStack.back() && lookup[charStack.back()] > 0)
            {
                used.erase(charStack.back());
                charStack.pop_back();
            }

            charStack.emplace_back(c);
            used.emplace(c);
        }

        return {charStack.begin(), charStack.end()};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.removeDuplicateLetters("bcabc"), "abc");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.removeDuplicateLetters("cbacdcbc"), "acdb");
}

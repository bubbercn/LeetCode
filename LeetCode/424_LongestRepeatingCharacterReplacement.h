#pragma once
#include "Common.h"

class Solution
{
public:
    int characterReplacement(const string &s, int k)
    {
        int left = 0, right = 0;
        int replace = 0;
        int result = 0;
        int length = 0;
        char maxChar = 0;
        unordered_map<char, int> lookup;
        while (left <= right)
        {
            if (replace <= k && right < s.length())
            {
                length++;
                lookup[s[right]]++;
                if (maxChar == 0 || (maxChar != s[right] && lookup[s[right]] > lookup[maxChar]))
                {
                    maxChar = s[right];
                }
                right++;
                replace = length - lookup[maxChar];
                if (replace <= k)
                {
                    result = max(result, length);
                }
            }
            else
            {
                length--;
                lookup[s[left]]--;
                if (s[left] == maxChar)
                {
                    for (auto& i : lookup)
                    {
                        if (i.second > lookup[maxChar])
                        {
                            maxChar = i.first;
                        }
                    }
                }
                if (lookup[s[left]] == 0)
                {
                    lookup.erase(s[left]);
                }
                left++;
                replace = length - lookup[maxChar];
            }
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
    EXPECT_EQ(solution.characterReplacement("ABAB", 2), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.characterReplacement("AABABBA", 1), 4);
}

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.characterReplacement("AABABBB", 1), 5);
}

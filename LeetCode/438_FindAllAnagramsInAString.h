#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (s.length() < p.length())
            return {};

        unsigned flag = 0;
        auto setFlag = [&flag](int value, int index) {
            if (value == 0)
            {
                flag &= ~(1 << index);
            }
            else
            {
                flag |= (1 << index);
            }
        };
        vector<int> lookup(26, 0);
        vector<int> result;
        for (auto c : p)
        {
            lookup[c - 'a']++;
            setFlag(lookup[c - 'a'], c - 'a');
        }
        for (int i = 0; i < p.length(); i++)
        {
            lookup[s[i] - 'a']--;
            setFlag(lookup[s[i] - 'a'], s[i] - 'a');
            if (!flag)
                result.emplace_back(i + 1 - p.length());
        }

        for (int i = p.length(); i < s.length(); i++)
        {
            lookup[s[i - p.length()] - 'a']++;
            setFlag(lookup[s[i - p.length()] - 'a'], s[i - p.length()] - 'a');
            lookup[s[i] - 'a']--;
            setFlag(lookup[s[i] - 'a'], s[i] - 'a');
            if (!flag)
                result.emplace_back(i + 1 - p.length());
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
    vector<int> output = {0, 6};
    EXPECT_EQ(solution.findAnagrams("cbaebabacd", "abc"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {0, 1, 2};
    EXPECT_EQ(solution.findAnagrams("abab", "ab"), output);
}
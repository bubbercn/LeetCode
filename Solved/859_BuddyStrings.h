#pragma once
#include "Common.h"

class Solution
{
public:
    bool buddyStrings(string_view s, string_view goal)
    {
        if (s.length() != goal.length())
            return false;

        list<int> diff;
        vector<int> count(26);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != goal[i])
            {
                if (diff.size() < 2)
                {
                    diff.emplace_back(i);
                }
                else
                {
                    return false;
                }
            }
            
            count[s[i] - 'a']++;
        }

        if (diff.empty())
        {
            for (int i = 0; i < 26; i++)
            {
                if (count[i] > 1)
                    return true;
            }
            return false;
        }

        if (diff.size() == 1)
            return false;
        
        int i1 = *diff.begin();
        int i2 = *(diff.rbegin());

        return s[i1] == goal[i2] && s[i2] == goal[i1];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.buddyStrings("ab", "ba"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.buddyStrings("ab", "ab"), false);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.buddyStrings("aa", "aa"), true);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.buddyStrings("ab", "babbb"), false);
}
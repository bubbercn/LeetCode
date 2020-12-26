#pragma once
#include "Common.h"

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        vector<int> lookup(26, 0);
        for (auto c : s)
        {
            lookup[c - 'a']++;
        }
        for (auto c : t)
        {
            if (lookup[c - 'a'] == 0)
                return c;
            lookup[c - 'a']--;
        }
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.findTheDifference("abcd", "abcde"), 'e');
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findTheDifference("", "y"), 'y');
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.findTheDifference("a", "aa"), 'a');
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.findTheDifference("ae", "aea"), 'a');
}

#pragma once
#include "Common.h"

class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        vector<int> lookup(26, 0);
        for (auto c : s)
        {
            lookup[c - 'a']++;
        }

        int result = INT_MIN;
        int begin = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (lookup[s[i] - 'a'] < k)
            {
                if (begin == -1)
                {
                    result = max(result, 0);
                }
                else
                {
                    result = max(result, longestSubstring(s.substr(begin, i - begin), k));
                    begin = -1;
                }
            }
            else
            {
                if (begin == -1)
                {
                    begin = i;
                }
            }
        }

        if (begin != -1)
        {
            if (begin == 0)
            {
                result = s.length();
            }
            else
            {
                result = max(result, longestSubstring(s.substr(begin), k));
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
    EXPECT_EQ(solution.longestSubstring("aaabb", 3), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.longestSubstring("ababbc", 2), 5);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.longestSubstring("ababacb", 3), 0);
}

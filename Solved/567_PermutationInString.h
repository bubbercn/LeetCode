#pragma once
#include "Common.h"

class Solution
{
public:
    bool checkInclusion(string_view s1, string_view s2)
    {
        if (s1.size() > s2.size())
            return false;

        vector<int> f1(26, 0);
        for (auto c : s1)
        {
            f1[c - 'a']++;
        }

        vector<int> f2(26, 0);
        for (int i = 0; i < s2.length(); i++)
        {
            f2[s2[i] - 'a']++;
            if (i >= s1.length())
            {
                f2[s2[i - s1.length()] - 'a']--;
            }
            if (i >= s1.length() - 1 && f1 == f2)
                return true;
        }
        return false;;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.checkInclusion("ab", "eidbaooo"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.checkInclusion("ab", "eidboaoo"), false);
}
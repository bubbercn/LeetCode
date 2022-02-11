#pragma once
#include "Common.h"

class Solution
{
public:
    int repeatedStringMatch(string_view a, string_view b)
    {
        vector<int> next = generateNext(b);
        int result = 1;
        int posA = 0, posB = 0, lastPosB = posB;
        while (posB < b.length() && posA + (result - 1) * a.length() - posB < a.length())
        {
            if (posA == a.length())
            {
                posA = 0;
                result++;
            }
            if (a[posA] == b[posB])
            {
                posA++;
                posB++;
            }
            else if (posB == 0)
            {
                posA++;
            }
            else
            {
                posB = next[posB - 1];
            }
        }
        return posB == b.length() ? result : -1;
    }

private:
    vector<int> generateNext(string_view s)
    {
        vector<int> result(s.length(), 0);
        int i = 1, now = 0;
        while (i < s.length())
        {
            if (s.at(now) == s[i])
            {
                result[i] = ++now;
                i++;
            }
            else if (now == 0)
            {
                result[i] = 0;
                i++;
            }
            else
            {
                now = result[now - 1];
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
    EXPECT_EQ(solution.repeatedStringMatch("abcd", "cdabcdab"), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.repeatedStringMatch("a", "aa"), 2);
}

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.repeatedStringMatch("ab", "ac"), -1);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.repeatedStringMatch("aaac", "aac"), 1);
}
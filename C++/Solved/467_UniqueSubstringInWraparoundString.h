#pragma once
#include "Common.h"

class Solution
{
public:
    int findSubstringInWraproundString(const string &p)
    {
        if (p.empty())
            return 0;

        vector<int> lookup(26, 0);
        int length = 1;
        for (int i = p.length() - 1; i >= 0; i--)
        {
            if (i < p.length() - 1 && isAdjacent(p[i], p[i + 1]))
            {
                length++;
            }
            else
            {
                length = 1;
            }

            lookup[p[i] - 'a'] = max(lookup[p[i] - 'a'], length);
        }
        return accumulate(lookup.begin(), lookup.end(), 0);
    }

private:
    bool isAdjacent(char c1, char c2)
    {
        return (c1 == 'z' && c2 == 'a') || c1 + 1 == c2;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.findSubstringInWraproundString("a"), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findSubstringInWraproundString("cac"), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.findSubstringInWraproundString("zab"), 6);
}
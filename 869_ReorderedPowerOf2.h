#pragma once
#include "Common.h"

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        if (lookup.empty())
        {
            for (int i = 0;; i++)
            {
                int v = pow(2, i);
                if (v > 1e9)
                    break;
                string s = to_string(v);
                sort(s.begin(), s.end());
                lookup.emplace(s);
            }
        }
        string s = to_string(n);
        sort(s.begin(), s.end());
        return lookup.count(s) != 0;
    }

private:
    inline static unordered_set<string> lookup;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.reorderedPowerOf2(1), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.reorderedPowerOf2(10), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.reorderedPowerOf2(46), true);
}
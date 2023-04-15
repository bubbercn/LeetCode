#pragma once
#include "Common.h"

class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> lookup;
        for (auto num : deck)
        {
            lookup[num]++;
        }
        int x = lookup.begin()->second;
        if (x <= 1)
            return false;
        for (auto it = ++lookup.begin(); it != lookup.end(); it++)
        {
            x = gcd(x, it->second);
            if (x <= 1)
                return false;
        }
        return true;
    }

private:
    int gcd(int x, int y)
    {
        int z = y;
        while (x % y != 0)
        {
            z = x % y;
            x = y;
            y = z;
        }
        return z;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> deck = {1, 2, 3, 4, 4, 3, 2, 1};
    EXPECT_EQ(solution.hasGroupsSizeX(deck), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> deck = {1, 1, 1, 2, 2, 2, 3, 3};
    EXPECT_EQ(solution.hasGroupsSizeX(deck), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> deck = {1};
    EXPECT_EQ(solution.hasGroupsSizeX(deck), false);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> deck = {1, 1, 1, 1, 2, 2, 2, 2, 2, 2};
    EXPECT_EQ(solution.hasGroupsSizeX(deck), true);
}
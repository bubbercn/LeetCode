#pragma once
#include "Common.h"

class Solution
{
public:
    double soupServings(int n)
    {
        if (n >= 5000)
            return 1;
        lookup.clear();
        return helper(n, n, 1);
    }

private:
    double helper(int a, int b, double p)
    {
        if (a <= 0 && b <= 0)
            return p / 2;

        if (a <= 0)
            return p;

        if (b <= 0)
            return 0;

        if (auto it1 = lookup.find(a); it1 != lookup.end())
        {
            if (auto it2 = it1->second.find(b); it2 != it1->second.end())
            {
                return p * it2->second;
            }
        }

        double result = helper(a - 100, b, p * 0.25) + helper(a - 75, b - 25, p * 0.25) + helper(a - 50, b - 50, p * 0.25) + helper(a - 25, b - 75, p * 0.25);
        lookup[a][b] = result / p;
        return result;
    }
    unordered_map<int, unordered_map<int, double>> lookup;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.soupServings(50), 0.625);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.soupServings(100), 0.71875);
}
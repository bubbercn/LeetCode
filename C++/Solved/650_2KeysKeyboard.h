#pragma once
#include "Common.h"

class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;

        if (auto it = lookup.find(n); it != lookup.end())
        {
            return it->second;
        }

        int result = numeric_limits<int>::max();
        int x = sqrt(n);
        set<int> divisors;
        for (int i = 1; i <= x; i++)
        {
            if (n % i == 0)
            {
                divisors.emplace(i);
                if (i != 1)
                    divisors.emplace(n / i);
            }
        }
        for (auto divisor : divisors)
        {
            int temp = minSteps(divisor);
            temp += n / divisor;
            result = min(result, temp);
        }
        lookup.emplace(n, result);
        return result;
    }

private:
    unordered_map<int, int> lookup;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.minSteps(3), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.minSteps(1), 0);
}

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.minSteps(100), 14);
}

TEST_F(LeetCodeTest, Case2)
{
    EXPECT_EQ(solution.minSteps(1000), 21);
}

TEST_F(LeetCodeTest, Case3)
{
    EXPECT_EQ(solution.minSteps(18), 8);
}
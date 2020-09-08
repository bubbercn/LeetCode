#pragma once
#include "Common.h"

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> primes = {2, 7, 13, 19};
    EXPECT_EQ(solution.nthSuperUglyNumber(12, primes), 32);
}
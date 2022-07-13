#pragma once
#include "Common.h"

class Solution
{
public:
    int numTilings(int n)
    {
        if (n <= 1)
            return 1;

        if (n == 2)
            return 2;

        if (lookup[n] != -1)
            return lookup[n];

        int result = 0;
        result += numTilings(n - 3);
        result %= MOD;

        int temp = numTilings(n - 1) * 2;
        temp %= MOD;
        result += temp;
        result %= MOD;

        lookup[n] = result;
        return result;
    }

private:
    inline static vector<int> lookup = vector<int>(1001, -1);
    static constexpr int MOD = 1000000007;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.numTilings(3), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.numTilings(1), 1);
}

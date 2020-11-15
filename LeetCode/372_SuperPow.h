#pragma once
#include "Common.h"

constexpr int DEVIDER = 1337;

class Solution
{
public:
    int superPow(int a, vector<int> &b)
    {
        if (b.empty())
            return 1;

        a = (a >= DEVIDER) ? (a % DEVIDER) : a;

        int r = *b.rbegin();
        b.pop_back();

        return (helper(superPow(a, b), 10) * helper(a, r)) % DEVIDER;
    }

private:
    int helper(int a, int b)
    {
        a = (a >= DEVIDER) ? (a % DEVIDER) : a;

        if (b == 0)
            return 1;

        int r = 1;

        if (b % 2)
        {
            r = a;
        }
        b /= 2;
        return (helper(a * a, b) * r) % DEVIDER;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.superPow(2, vector<int>{3}), 8);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.superPow(2, vector<int>{1, 0}), 1024);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.superPow(1, vector<int>{4, 3, 3, 8, 5, 2}), 1);
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.superPow(2147483647, vector<int>{2, 0, 0}), 1198);
}

TEST_F(LeetCodeTest, BigNumber)
{
    EXPECT_EQ(solution.superPow(2147483647, vector<int>{1}), 932);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    EXPECT_EQ(solution.compress(chars), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<char> chars = {'a'};
    EXPECT_EQ(solution.compress(chars), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    EXPECT_EQ(solution.compress(chars), 4);
}

TEST_F(LeetCodeTest, Example4)
{
    vector<char> chars = {'a', 'a', 'a', 'b', 'b', 'a', 'a'};
    EXPECT_EQ(solution.compress(chars), 6);
}
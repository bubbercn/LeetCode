#pragma once
#include "Common.h"

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<char> input = {'h', 'e', 'l', 'l', 'o'};
    vector<char> output = {'o', 'l', 'l', 'e', 'h'};
    solution.reverseString(input);
    EXPECT_EQ(input, output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<char> input = {'H', 'a', 'n', 'n', 'a', 'h'};
    vector<char> output = {'h', 'a', 'n', 'n', 'a', 'H'};
    solution.reverseString(input);
    EXPECT_EQ(input, output);
}
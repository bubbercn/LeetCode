#pragma once
#include "Common.h"

class Solution {
public:
    int maxProduct(vector<string>& words) {
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
    vector<string> input = {"abcw","baz","foo","bar","xtfn","abcdef"};
    EXPECT_EQ(solution.maxProduct(input), 16);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> input = {"a","ab","abc","d","cd","bcd","abcd"};
    EXPECT_EQ(solution.maxProduct(input), 4);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> input = {"a","aa","aaa","aaaa"};
    EXPECT_EQ(solution.maxProduct(input), 0);
}


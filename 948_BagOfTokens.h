#pragma once
#include "Common.h"

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
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
    vector<int> tokens = {100};
    EXPECT_EQ(solution.bagOfTokensScore(tokens, 50), 0);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> tokens = {100, 200};
    EXPECT_EQ(solution.bagOfTokensScore(tokens, 150), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> tokens = {100, 200, 300, 400};
    EXPECT_EQ(solution.bagOfTokensScore(tokens, 200), 2);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> output = {1,10,11,12,13,2,3,4,5,6,7,8,9};
    EXPECT_EQ(solution.lexicalOrder(13), output);
}

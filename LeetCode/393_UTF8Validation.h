#pragma once
#include "Common.h"

class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
    inline static vector<int> data;
};

TEST_F(LeetCodeTest, Example1)
{
    data = {197, 130, 1};
    EXPECT_EQ(solution.validUtf8(data), true);
}

TEST_F(LeetCodeTest, Example2)
{
    data = {1235, 140, 4};
    EXPECT_EQ(solution.validUtf8(data), false);
}

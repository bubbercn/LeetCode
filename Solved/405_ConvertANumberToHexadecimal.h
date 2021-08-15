#pragma once
#include "Common.h"

class Solution
{
public:
    string toHex(int num)
    {
        stringstream result;
        result << hex << static_cast<unsigned int>(num);
        return result.str();
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.toHex(26), "1a");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.toHex(-1), "ffffffff");
}

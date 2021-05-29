#pragma once
#include "Common.h"

class Solution
{
public:
    string validIPAddress(const string &IP)
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
    EXPECT_EQ(solution.validIPAddress("172.16.254.1"), "IPv4");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334"), "IPv6");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.validIPAddress("256.256.256.256"), "Neither");
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:"), "Neither");
}

TEST_F(LeetCodeTest, Example5)
{
    EXPECT_EQ(solution.validIPAddress("1e1.4.5.6"), "Neither");
}
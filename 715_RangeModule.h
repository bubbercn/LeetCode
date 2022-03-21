#pragma once
#include "Common.h"

class RangeModule
{
public:
    RangeModule()
    {
    }

    void addRange(int left, int right)
    {
    }

    bool queryRange(int left, int right)
    {
        return false;
    }

    void removeRange(int left, int right)
    {
    }
};

class Solution
{
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    RangeModule rangeModule;
    rangeModule.addRange(10, 20);
    rangeModule.removeRange(14, 16);
    EXPECT_TRUE(rangeModule.queryRange(10, 14));
    EXPECT_FALSE(rangeModule.queryRange(13, 15));
    EXPECT_TRUE(rangeModule.queryRange(16, 17));
}
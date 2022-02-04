#pragma once
#include "Common.h"

class MapSum
{
public:
    MapSum()
    {
    }

    void insert(string_view key, int val)
    {
    }

    int sum(string_view prefix)
    {
        return 0;
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
    MapSum mapSum;
    mapSum.insert("apple", 3);
    EXPECT_EQ(mapSum.sum("ap"), 3);
    mapSum.insert("app", 2);
    EXPECT_EQ(mapSum.sum("ap"), 5);
}
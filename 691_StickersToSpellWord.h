#pragma once
#include "Common.h"

class Solution
{
public:
    int minStickers(vector<string> &stickers, string_view target)
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
    vector<string> stickers = {"with", "example", "science"};
    EXPECT_EQ(solution.minStickers(stickers, "thehat"), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> stickers = {"notice", "possible"};
    EXPECT_EQ(solution.minStickers(stickers, "basicbasic"), -1);
}
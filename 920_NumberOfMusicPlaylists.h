#pragma once
#include "Common.h"

class Solution
{
public:
    int numMusicPlaylists(int n, int goal, int k)
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
    EXPECT_EQ(solution.numMusicPlaylists(3, 3, 1), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.numMusicPlaylists(2, 3, 0), 6);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.numMusicPlaylists(2, 3, 1), 2);
}
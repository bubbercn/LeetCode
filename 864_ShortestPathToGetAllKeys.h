#pragma once
#include "Common.h"

class Solution
{
public:
    int shortestPathAllKeys(vector<string> &grid)
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
    vector<string> grid = {"@.a..", "###.#", "b.A.B"};
    EXPECT_EQ(solution.shortestPathAllKeys(grid), 8);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> grid = {"@..aA", "..B#.", "....b"};
    EXPECT_EQ(solution.shortestPathAllKeys(grid), 6);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> grid = {"@Aa"};
    EXPECT_EQ(solution.shortestPathAllKeys(grid), -1);
}
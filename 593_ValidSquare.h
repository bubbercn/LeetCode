#pragma once
#include "Common.h"

class Solution
{
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> p1 = {0, 0}, p2 = {1, 1}, p3 = {1, 0}, p4 = {0, 1};
    EXPECT_EQ(solution.validSquare(p1, p2, p3, p4), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> p1 = {0, 0}, p2 = {1, 1}, p3 = {1, 0}, p4 = {0, 12};
    EXPECT_EQ(solution.validSquare(p1, p2, p3, p4), false);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> p1 = {1, 0}, p2 = {-1, 0}, p3 = {0, 1}, p4 = {0, -1};
    EXPECT_EQ(solution.validSquare(p1, p2, p3, p4), true);
}

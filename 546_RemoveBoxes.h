#pragma once
#include "Common.h"

class Solution
{
public:
    int removeBoxes(vector<int> &boxes)
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
    vector<int> boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    EXPECT_EQ(solution.removeBoxes(boxes), 23);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> boxes = {1, 1, 1};
    EXPECT_EQ(solution.removeBoxes(boxes), 9);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> boxes = {1};
    EXPECT_EQ(solution.removeBoxes(boxes), 1);
}
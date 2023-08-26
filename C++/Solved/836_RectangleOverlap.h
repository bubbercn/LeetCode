#pragma once
#include "Common.h"

class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        return isOverlap(rec1[0], rec1[2], rec2[0], rec2[2]) && isOverlap(rec1[1], rec1[3], rec2[1], rec2[3]);
    }

private:
    bool isOverlap(int x1, int x2, int y1, int y2)
    {
        return !(x2 <= y1 || x1 >= y2);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};
    EXPECT_EQ(solution.isRectangleOverlap(rec1, rec2), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> rec1 = {0, 0, 1, 1};
    vector<int> rec2 = {1, 0, 2, 1};
    EXPECT_EQ(solution.isRectangleOverlap(rec1, rec2), false);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> rec1 = {0, 0, 1, 1};
    vector<int> rec2 = {2, 2, 3, 3};
    EXPECT_EQ(solution.isRectangleOverlap(rec1, rec2), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> rec1 = {7, 8, 13, 15};
    vector<int> rec2 = {10, 8, 12, 20};
    EXPECT_EQ(solution.isRectangleOverlap(rec1, rec2), true);
}
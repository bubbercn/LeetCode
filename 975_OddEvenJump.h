#pragma once
#include "Common.h"

class Solution
{
public:
    int oddEvenJumps(vector<int> &arr)
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
    vector<int> arr = {10, 13, 12, 14, 15};
    EXPECT_EQ(solution.oddEvenJumps(arr), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {2, 3, 1, 1, 4};
    EXPECT_EQ(solution.oddEvenJumps(arr), 3);
}
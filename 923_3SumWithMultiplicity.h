#pragma once
#include "Common.h"

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
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
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    EXPECT_EQ(solution.threeSumMulti(arr, 8), 20);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {1, 1, 2, 2, 2, 2};
    EXPECT_EQ(solution.threeSumMulti(arr, 5), 12);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> arr = {2, 1, 3};
    EXPECT_EQ(solution.threeSumMulti(arr, 6), 1);
}

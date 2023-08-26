#pragma once
#include "Common.h"

class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        unordered_set<int> candyTypes;
        for (auto type : candyType)
        {
            candyTypes.emplace(type);
        }
        return min(candyTypes.size(), candyType.size() / 2);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> candyType = {1, 1, 2, 2, 3, 3};
    EXPECT_EQ(solution.distributeCandies(candyType), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> candyType = {1, 1, 2, 3};
    EXPECT_EQ(solution.distributeCandies(candyType), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> candyType = {6, 6, 6, 6};
    EXPECT_EQ(solution.distributeCandies(candyType), 1);
}
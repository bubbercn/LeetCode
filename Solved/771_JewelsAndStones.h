#pragma once
#include "Common.h"

class Solution
{
public:
    int numJewelsInStones(string_view jewels, string_view stones)
    {
        int result = 0;
        unordered_set<char> jewelsSet;
        for (auto jewell : jewels)
        {
            jewelsSet.emplace(jewell);
        }
        for (auto stone : stones)
        {
            if (jewelsSet.find(stone) != jewelsSet.end())
                result++;
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.numJewelsInStones("aA", "aAAbbbb"), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.numJewelsInStones("z", "ZZ"), 0);
}
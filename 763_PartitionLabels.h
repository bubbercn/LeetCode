#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> partitionLabels(string_view s)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> output = {9, 7, 8};
    EXPECT_EQ(solution.partitionLabels("ababcbacadefegdehijhklij"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {10};
    EXPECT_EQ(solution.partitionLabels("eccbbbbdec"), output);
}
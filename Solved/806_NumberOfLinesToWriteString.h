#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string_view s)
    {
        int lineCount = 1;
        int left = 100;
        for (auto c : s)
        {
            left -= widths[c - 'a'];
            if (left < 0)
            {
                lineCount++;
                left = 100 - widths[c - 'a'];
            }
        }
        return {lineCount, 100 - left};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> widths = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    vector<int> output = {3, 60};
    EXPECT_EQ(solution.numberOfLines(widths, "abcdefghijklmnopqrstuvwxyz"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> widths = {4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    vector<int> output = {2, 4};
    EXPECT_EQ(solution.numberOfLines(widths, "bbbcccdddaaa"), output);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> readBinaryWatch(int num)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
    inline static vector<string> output;
};

TEST_F(LeetCodeTest, Example1)
{
    output = {"1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"};
    EXPECT_EQ(solution.readBinaryWatch(1), output);
}

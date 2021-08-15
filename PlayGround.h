#pragma once
#include "Common.h"

class Solution
{
public:
    int XXX(vector<int> &nums)
    {
        return 0;
    }

private:
    inline static constexpr int limit = 1000000000 + 7;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 2, 3, 2};
    EXPECT_EQ(solution.XXX(nums), 14);
}

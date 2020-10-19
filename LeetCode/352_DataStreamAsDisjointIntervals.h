#pragma once
#include "Common.h"

class SummaryRanges
{
public:
    /** Initialize your data structure here. */
    SummaryRanges()
    {
    }

    void addNum(int val)
    {
    }

    vector<vector<int>> getIntervals()
    {
        return {};
    }
};

class Solution
{
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> input = {1, 3, 7, 2, 6};
    unique_ptr<SummaryRanges> obj(new SummaryRanges());
    for (auto val : input)
    {
        obj->addNum(val);
    }
    vector<vector<int>> result = obj->getIntervals();
}

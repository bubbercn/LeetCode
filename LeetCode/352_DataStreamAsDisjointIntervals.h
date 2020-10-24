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
        if (intervals.empty())
        {
            intervals.push_back({val, val});
            return;
        }

        int begin = 0;
        int end = intervals.size() - 1;

        while (begin < end)
        {
            int middle = (begin + end) / 2;
            if (val >= intervals[middle][0] && val <= intervals[middle][1])
            {
                return;
            }
            else if (val < intervals[middle][0])
            {
                end = middle - 1;
            }
            else
            {
                begin = middle + 1;
            }
        }

        if (begin == end)
        {
            if (val < intervals[end][0])
            {
                if (begin > 0)
                {
                    begin--;
                }
            }
            else if (end + 1 < static_cast<int>(intervals.size()))
            {
                end++;
            }
        }
        else
        {
            swap(begin, end);
        }

        if (intervals[begin][1] == val - 1)
        {
            intervals[begin][1] = val;
            if (intervals[end][0] == val + 1)
            {
                intervals[begin][1] = intervals[end][1];
                intervals.erase(intervals.begin() + end);
            }
        }
        else if (intervals[end][0] == val + 1)
        {
            intervals[end][0] = val;
            if (intervals[begin][1] == val - 1)
            {
                intervals[end][0] = intervals[begin][0];
                intervals.erase(intervals.begin() + begin);
            }
        }
        else if (intervals[begin][1] < val - 1)
        {
            intervals.insert(intervals.begin() + begin + 1, {val, val});
        }
        else if (intervals[end][0] > val + 1)
        {
            intervals.insert(intervals.begin() + end, {val, val});
        }
    }

    vector<vector<int>> getIntervals()
    {
        return {intervals.begin(), intervals.end()};
    }

private:
    vector<vector<int>> intervals;
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

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> input = {1, 9, 2};
    unique_ptr<SummaryRanges> obj(new SummaryRanges());
    for (auto val : input)
    {
        obj->addNum(val);
    }
    vector<vector<int>> result = obj->getIntervals();
}

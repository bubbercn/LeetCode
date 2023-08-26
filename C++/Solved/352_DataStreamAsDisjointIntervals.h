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

        while (begin <= end)
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
        
        swap(begin, end);
        if (end == static_cast<int>(intervals.size()))
        {
            end--;
        }
        if (begin < 0)
        {
            begin = 0;
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

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> input = {49, 97, 53, 5, 33, 65, 62, 51, 100, 38, 61, 45, 74, 27, 64, 17, 36, 17, 96, 12, 79, 32, 68, 90, 77, 18, 39, 12, 93, 9, 87, 42, 60, 71, 12, 45, 55, 40, 78, 81, 26, 70, 61, 56, 66, 33, 7, 70, 1, 11, 92, 51, 90, 100, 85, 80, 0, 78, 63, 42, 31, 93, 41, 90, 8, 24, 72, 28, 30, 18, 69, 57, 11, 10, 40, 65, 62, 13, 38, 70, 37, 90, 15, 70, 42, 69, 26, 77, 70, 75, 36, 56, 11, 76, 49, 40, 73, 30, 37, 23};
    unique_ptr<SummaryRanges> obj(new SummaryRanges());
    for (auto val : input)
    {
        obj->addNum(val);
    }
    vector<vector<int>> result = obj->getIntervals();
}

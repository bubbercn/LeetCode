#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> partitionLabels(string_view s)
    {
        vector<pair<int, int>> intervals(26, {numeric_limits<int>::max(), 0});
        for (int i = 0; i < s.length(); i++)
        {
            int index = s[i] - 'a';
            if (i < intervals[index].first)
            {
                intervals[index].first = i;
            }
            intervals[index].second = i;
        }
        sort(intervals.begin(), intervals.end());
        int begin = intervals[0].first;
        int end = intervals[0].second;
        vector<int> result;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].first == numeric_limits<int>::max())
                continue;
            
            if (intervals[i].first > end)
            {
                result.emplace_back(end - begin + 1);
                begin = intervals[i].first;
                end = intervals[i].second;
            }
            else 
            {
                end = max(end, intervals[i].second);
            }
        }
        result.emplace_back(end - begin + 1);
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
    vector<int> output = {9, 7, 8};
    EXPECT_EQ(solution.partitionLabels("ababcbacadefegdehijhklij"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {10};
    EXPECT_EQ(solution.partitionLabels("eccbbbbdec"), output);
}
#pragma once
#include "Common.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        set<vector<int>> temp(intervals.begin(), intervals.end());
        auto i = temp.insert(newInterval);
        if (i.second)
        {
            vector<vector<int>> result(temp.begin(), temp.end());
            return merge(result);
        }
        return intervals;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= intervals[i - 1][1])
            {
                intervals[i][0] = intervals[i - 1][0];
                if (intervals[i][1] < intervals[i - 1][1])
                {
                    intervals[i][1] = intervals[i - 1][1];
                }
                intervals[i - 1].clear();
            }
        }
        
        vector<vector<int>> result;
        for (auto i = intervals.begin(); i != intervals.end(); i++)
        {
            if (!i->empty())
            {
                result.emplace_back(*i);
            }
        }
        return result;
    }
};

void Test()
{
    Solution solution;
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    solution.insert(intervals, newInterval);
}

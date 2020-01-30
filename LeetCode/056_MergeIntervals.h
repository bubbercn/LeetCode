#pragma once
#include "Common.h"

class Solution {
public:
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
    
    vector<vector<int>> input1 = {
        {15,18},
        {8,10},
        {1,3},
        {2,6},
    };
    vector<vector<int>> output1 = {
        {1,6},
        {8,10},
        {15,18}
    };
    assert(solution.merge(input1) == output1);
    
    vector<vector<int>> input2 = {
        {1,4},
        {4,5}
    };
    vector<vector<int>> output2 = {
        {1,5},
    };
    assert(solution.merge(input2) == output2);
}

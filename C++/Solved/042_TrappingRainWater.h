#pragma once
#include "Common.h"

class Solution
{
    int getOneTrap(vector<int>::const_iterator& begin, vector<int>::const_iterator end)
    {
        int left_max = *begin;
        int min = *begin;
        auto begin2 = begin;
        
        while (++begin != end && *begin <= min)
        {
            min = *begin;
        }
        
        if (begin == end)
        {
            return 0;
        }
        
        int right_max = *begin;
        
        while (++begin != end && *begin >= right_max)
        {
            right_max = *begin;
        }
        
        int result = 0;
        
        int max = (left_max < right_max ? left_max : right_max);
        
        while (++begin2 != begin)
        {
            result += ((max - *begin2) > 0 ? (max - *begin2) : 0);
        }
        
        return result;
    }
    
public:
    int trap(vector<int>& height)
    {
        if (height.size() == 0)
            return 0;
        
        vector<int> max_height(height.size());
        int max = height[0];
        max_height[0] = 0;
        
        for (int i = 1; i < height.size(); i++)
        {
            max_height[i] = max;
            if (height[i] > max)
            {
                max = height[i];
            }
        }
        
        max_height[height.size() - 1] = 0;
        max = height[height.size() - 1];
        
        for (int i = static_cast<int>(height.size() - 2); i >= 0; i--)
        {
            if (max < max_height[i])
            {
                max_height[i] = max;
            }
            if (height[i] > max)
            {
                max = height[i];
            }
        }
        
        int result = 0;
        for (int i = 0; i < height.size(); i++)
        {
            result += (max_height[i] - height[i] > 0 ? max_height[i]- height[i] : 0);
        }
        
        return result;
    }
};

void Test()
{
    Solution solution;

    vector<int> input1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    assert(solution.trap(input1) == 6);
    
    vector<int> input2 = {2, 1, 0, 2};
    assert(solution.trap(input2) == 3);
    
    vector<int> input3 = {5, 2, 1, 2, 1, 5};
    assert(solution.trap(input3) == 14);
}

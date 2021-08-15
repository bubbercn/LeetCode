#pragma once
#include "Common.h"

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> lookup(nums.begin(), nums.end());
        
        int maxLength = 0;
        int currentLength = 0;
        
        while (!lookup.empty())
        {
            currentLength = 1;
            int currentValue = *lookup.begin();
            lookup.erase(currentValue);
            
            int i = currentValue;
            while(lookup.find(i - 1) != lookup.end())
            {
                lookup.erase(i - 1);
                i--;
                currentLength++;
            }
            
            i = currentValue;
            while(lookup.find(i + 1) != lookup.end())
            {
                lookup.erase(i + 1);
                i++;
                currentLength++;
            }
            
            maxLength = max(maxLength, currentLength);
        }
        
        return maxLength;
    }
};

void Test()
{
    Solution solution;
    vector<int> input;
    
    input = {100, 4, 200, 1, 3, 2};
    assert(solution.longestConsecutive(input) == 4);
}

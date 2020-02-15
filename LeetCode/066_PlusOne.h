#pragma once
#include "Common.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        if (digits.size() == 0)
            return digits;
        
        (*digits.rbegin())++;
        
        int add = 0;
        
        for (auto i = digits.rbegin(); i != digits.rend(); i++)
        {
            *i += add;
            if (*i >= 10)
            {
                *i -= 10;
                add = 1;
            }
            else
            {
                add = 0;
            }
        }
        
        if (add == 1)
        {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};

void Test()
{
    Solution solution;
    vector<int> input1 = {1, 2, 3};
    vector<int> output1 = {1, 2, 4};
    assert(solution.plusOne(input1) == output1);
    
    vector<int> input2 = {4, 3, 2, 1};
    vector<int> output2 = {4, 3, 2, 2};
    assert(solution.plusOne(input2) == output2);
    
    vector<int> input3 = {9};
    vector<int> output3 = {1, 0};
    assert(solution.plusOne(input3) == output3);
}

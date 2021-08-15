#pragma once
#include "Common.h"

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        size_t N = gas.size();
        vector<int> diff(N);
        for (size_t i = 0; i < N; i++)
        {
            diff[i] = gas[i] - cost[i];
        }
        size_t begin = findNextPositive(diff, 0);
        
        if (begin == N)
            return -1;
        
        int sum = diff[begin];
        size_t end = plusOne(begin, N);
        
        while (end != begin)
        {
            sum += diff[end];
            if (sum >= 0)
            {
                end = plusOne(end, N);
            }
            else
            {
                begin = plusOne(end, N);
                if (toTheEnd)
                    return -1;
                
                begin = findNextPositive(diff, begin);
                
                if (begin == N)
                    return -1;
                sum = diff[begin];
                end = plusOne(begin, N);
            }
        }
        
        if (sum >= 0)
        {
            return static_cast<int>(begin);
        }
        else
        {
            return -1;
        }
    }
private:
    size_t findNextPositive(const vector<int>& nums, size_t begin)
    {
        size_t N = nums.size();
        for (; begin < N; begin++)
        {
            if (nums[begin] >= 0)
                break;
        }
        return begin;
    }
    
    size_t plusOne(size_t i, size_t N)
    {
        size_t result = ++i;
        if (result == N)
        {
            toTheEnd = true;
            return 0;
        }
        else
        {
            return result;
        }
    }
    
    bool toTheEnd = false;
};

void Test()
{
    Solution solution;
    vector<int> gas, cost;
    
    gas  = {1,2,3,4,5};
    cost = {3,4,5,1,2};
    assert(solution.canCompleteCircuit(gas, cost) == 3);

    gas  = {2,3,4};
    cost = {3,4,3};
    assert(solution.canCompleteCircuit(gas, cost) == -1);
    
    gas  = {3,3,4};
    cost = {3,4,4};
    assert(solution.canCompleteCircuit(gas, cost) == -1);

}

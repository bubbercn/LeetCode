#pragma once
#include "Common.h"

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n <= 0)
            return 0;
        
        if (pQ.empty())
            pQ.emplace(1);

        if (n <= curIndex)
            return uglyNumbers[n - 1];

        while (++curIndex < n)
        {
            double uglyNumber = pQ.top();
            pQ.emplace(uglyNumber * 2);
            pQ.emplace(uglyNumber * 3);
            pQ.emplace(uglyNumber * 5);
            uglyNumbers[curIndex] = uglyNumber;
            do
            {
                pQ.pop();
            } while (pQ.top() == uglyNumber);
        }
        curIndex--;

        return uglyNumbers[n - 1];
    }

private:
    vector<int> uglyNumbers = vector<int>(1690);
    priority_queue<double, vector<double>, greater<double>> pQ;
    int curIndex = -1;
};

void Test()
{
    Solution solution;
    // assert(solution.nthUglyNumber(1) == 1);
    // assert(solution.nthUglyNumber(10) == 12);
    // assert(solution.nthUglyNumber(1407) == 536870912);
    assert(solution.nthUglyNumber(1690) == 536870912);
}
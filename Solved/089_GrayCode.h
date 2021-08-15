#pragma once
#include "Common.h"

class Solution {
public:
    vector<int> grayCode(int n) 
    {
        if (n == 0)
        {
            return {0};
        }

        vector<int> temp = grayCode(n - 1);
        vector<int> result(temp);

        int bit = 1 << (n - 1);

        for (auto i = temp.rbegin(); i != temp.rend(); i++)
        {
            result.emplace_back(*i | bit);
        }

        return result;
    }
};

void Test()
{
    Solution solution;
    solution.grayCode(2);
}
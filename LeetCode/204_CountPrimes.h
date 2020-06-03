#pragma once
#include "Common.h"

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> nums(n, 0);
        for (int i = 1; i < n; i++)
        {
            nums[i] = i;
        }

        for (int i = 2; i * i < n; i++)
        {
            if (nums[i] == 0)
                continue;

            for (int j = i; j * i < n; j++)
            {
                nums[j * i] = 0;
            }
        }

        int result = 0;

        for (int i = 2; i < n; i++)
        {
            if (nums[i] != 0)
                result++;
        }

        return result;
    }
};

void Test()
{
    Solution solution;
    assert(solution.countPrimes(10) == 4);
}

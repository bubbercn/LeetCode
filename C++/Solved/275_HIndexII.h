#pragma once
#include "Common.h"

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int high = citations.size();
        int low = 1;
        while (low <= high)
        {
            int middle = (low + high) / 2;
            int temp = citations.size() - middle + 1;
            if (citations[middle - 1] == temp)
            {
                return temp;
            }
            else if (citations[middle - 1] < temp)
            {
                low = middle + 1;
            }
            else
            {
                high = middle - 1;
            }
        }
        return citations.size() - low + 1;
    }
};

void Test()
{
    Solution solution;
    vector<int> citations;

    citations ={ 0, 1, 3, 5, 6 };
    assert(solution.hIndex(citations) == 3);

    citations ={ 100 };
    assert(solution.hIndex(citations) == 1);
}
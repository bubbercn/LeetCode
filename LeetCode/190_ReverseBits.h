#pragma once
#include "Common.h"

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++)
        {
            result |= ((n & 1) << (31 - i));
            n >>= 1;
        }
        return result;
    }
};

void Test()
{
    Solution solution;
    assert(solution.reverseBits(43261596) == 964176192);
    assert(solution.reverseBits(4294967293) == 3221225471);
}
#pragma once
#include "Common.h"

int rand7();

class Solution
{
public:
    int rand10()
    {
        int result = 0;
        do
        {
            result = (randomBit() << 3) + (randomBit() << 2) + (randomBit() << 1) + randomBit();
        } while (result > 9);
        return rand7() * 10 / 7;
    }

private:
    int randomBit()
    {
        int result = 0;
        do
        {
            result = rand7();
        } while (result == 4);
        return result < 4 ? 0 : 1;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

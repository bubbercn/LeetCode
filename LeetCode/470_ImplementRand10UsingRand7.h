#pragma once
#include "Common.h"

int rand7();

class Solution
{
public:
    int rand10()
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

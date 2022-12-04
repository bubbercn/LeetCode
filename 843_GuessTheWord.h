#pragma once
#include "Common.h"

// This is the Master's API interface.
// You should not implement it, or speculate about its implementation
class Master
{
public:
    int guess(string word)
    {
        return 0;
    }
};

class Solution
{
public:
    void findSecretWord(vector<string> &words, Master &master)
    {
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

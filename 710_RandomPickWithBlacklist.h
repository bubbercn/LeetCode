#pragma once
#include "Common.h"

class Solution
{
public:
    Solution()
    {
    }

    Solution(int n, const vector<int> &blacklist)
    {
    }

    int pick()
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    Solution solution(7, vector<int>({2, 3, 5}));
    solution.pick();
    solution.pick();
    solution.pick();
    solution.pick();
    solution.pick();
    solution.pick();
    solution.pick();
}

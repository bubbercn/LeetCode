#pragma once
#include "Common.h"

class Solution
{
public:
    int leastOpsExpressTarget(int x, int target)
    {
        lookup.clear();
        return helper(x, target) - 1;
    }

private:
    int helper(int x, int target)
    {
        if (auto i = lookup.find(x); i != lookup.end())
        {
            if (auto j = i->second.find(target); j != i->second.end())
            {
                return j->second;
            }
        }

        if (target < x)
        {
            return min(2 * target, (x - target) * 2 + 1);
        }

        long gain = x;
        int cost = 1;
        while (gain <= target)
        {
            if (gain == target)
            {
                lookup[x][target] = cost;
                return cost;
            }
            gain *= x;
            cost++;
        }
        gain /= x;
        cost--;
        int result = helper(x, target - gain) + cost;
        gain *= x;
        cost++;
        if (gain - target < target)
        {
            int temp = helper(x, gain - target) + cost;
            result = min(result, temp);
        }
        lookup[x][target] = result;
        return result;
    }

    static inline unordered_map<int, unordered_map<int, int>> lookup;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.leastOpsExpressTarget(3, 19), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.leastOpsExpressTarget(5, 501), 8);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.leastOpsExpressTarget(100, 100000000), 3);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.leastOpsExpressTarget(3, 365), 17);
}
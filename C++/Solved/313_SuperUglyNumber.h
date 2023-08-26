#pragma once
#include "Common.h"

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        if (n <= 0)
            return 0;

        priority_queue<int, vector<int>, greater<int>> pQ;
        unordered_set<int> lookup;
        int curIndex = -1;

        if (pQ.empty())
            pQ.emplace(1);

        int result = 0;

        while (++curIndex < n)
        {
            long uglyNumber = pQ.top();
            for (auto prime : primes)
            {
                long temp = uglyNumber * prime;
                if (temp <= INT32_MAX)
                {
                    auto x = lookup.emplace(temp);
                    if (x.second)
                    {
                        pQ.emplace(temp);
                    }
                }
            }
            result = static_cast<int>(uglyNumber);
            do
            {
                pQ.pop();
            } while (pQ.top() == uglyNumber);
        }

        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> primes = {2, 7, 13, 19};
    EXPECT_EQ(solution.nthSuperUglyNumber(12, primes), 32);
}
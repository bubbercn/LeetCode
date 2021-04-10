#pragma once
#include "Common.h"

class Solution
{
public:
    int findKthNumber(int n, int k)
    {
        int depth = 0;
        for (int i = n; i > 0; i /= 10)
        {
            depth++;
        }
        string result = helper(to_string(n), depth, k, false);
        return stoi(result);
    }

private:
    string helper(const string &limit, int depth, int &k, bool isCallByItself = true, bool updateK = true)
    {
        if (k == 0)
            return {};
        char start = isCallByItself ? '0' : '1';
        if (depth == 1)
        {
            if (!limit.empty() && k <= limit[0] - '0' + 1)
            {
                int temp = k;
                k = 0;
                return string(1, start + temp - 1);
            }
            else
            {
                k -= limit[0] - '0' + 1;
                return {};
            }
        }
        int nodesCount = 0;

        for (int i = 0, j = 1; i < depth; i++, j *= 10)
        {
            nodesCount += j;
        }
        char c = start;
        int temp = k;
        for (;temp > nodesCount; c++)
        {
            temp -= nodesCount;
            if (updateK)
            {
                k = temp;
            }
            else
            {
                c++;
            }
        }
        if (!limit.empty() && c == limit[0])
        {
            string temp = helper(limit.substr(1), depth - 1, --k);
            if (k != 0)
            {
                return string{++c} + helper(limit, depth, k, true, false);
            }
            else
            {
                return string({c}) + temp;
            }
        }
        else
        {
            return string({c}) + helper("", depth - 1, --k);
        }
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.findKthNumber(13, 2), 10);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findKthNumber(1, 1), 1);
}

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.findKthNumber(9, 2), 2);
}

TEST_F(LeetCodeTest, Case2)
{
    EXPECT_EQ(solution.findKthNumber(900, 112), 2);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.findKthNumber(10, 3), 2);
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.findKthNumber(100, 10), 17);
}

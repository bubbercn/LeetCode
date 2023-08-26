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
    int getNodesCount(int depth, const string &limit)
    {
        static unordered_map<int, int> lookup;

        long nodesCount = 0;

        if (auto it = lookup.find(depth); it != lookup.end())
        {
            nodesCount = it->second;
        }
        else
        {
            for (int i = 0, j = 1; i < depth; i++, j *= 10)
            {
                nodesCount += j;
            }
            lookup[depth] = nodesCount;
        }

        if (!limit.empty())
        {
            for (int i = 1, j = 1; i < depth; i++, j *= 10)
            {
                nodesCount -= ('9' - limit[depth - i - 1]) * j;
            }
        }

        return nodesCount;
    }
    string helper(const string &limit, int depth, int k, bool isCallByItself = true)
    {
        if (k == 0)
            return {};
        char start = isCallByItself ? '0' : '1';
        if (depth == 1)
        {
            return string(1, start + k - 1);
        }
        char c = start;
        int nodesCount = getNodesCount(depth, "");
        while (true)
        {
            if (!limit.empty() && c == limit[0])
            {
                nodesCount = getNodesCount(depth, limit.substr(1));
            }

            if (k <= nodesCount)
                break;

            k -= nodesCount;

            if (!limit.empty() && c == limit[0])
            {
                nodesCount = getNodesCount(--depth, "");
            }

            c++;
        }
        if (!limit.empty() && c == limit[0])
        {
            return string({c}) + helper(limit.substr(1), depth - 1, --k);
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

TEST_F(LeetCodeTest, Failure3)
{
    EXPECT_EQ(solution.findKthNumber(1692778, 1545580), 867519);
}

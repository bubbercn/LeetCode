#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> splitIntoFibonacci(string_view num)
    {
        lookup.clear();
        auto result = helper(num, num.length());
        if (result.empty())
            return {};
        return result[0];
    }

private:
    vector<vector<int>> helper(string_view num, int length)
    {
        if (length < 2)
            return {};

        if (length == 2)
        {
            int n1 = num[0] - '0';
            int n2 = num[1] - '0';
                return {{n1, n2}};
        }

        if (auto it = lookup.find(length); it != lookup.end())
            return it->second;

        int limit = (length + 1) / 2;
        vector<vector<int>> result;
        for (int i = 1; i <= limit; i++)
        {
            if (i != 1 and num[length - i] == '0')
                continue;

            int n3 = stoi(string(num.substr(length - i, i)));
            vector<vector<int>> temp = helper(num, length - i);
            for (auto pre : temp)
            {
                if (*pre.rbegin() + *(++pre.rbegin()) == n3)
                {
                    pre.emplace_back(n3);
                    result.emplace_back(pre);
                }
            }
        }
        lookup[length] = result;
        return result;
    }

    unordered_map<int, vector<vector<int>>> lookup;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> output = {11, 0, 11, 11};
    EXPECT_EQ(solution.splitIntoFibonacci("1101111"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {};
    EXPECT_EQ(solution.splitIntoFibonacci("112358130"), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> output = {};
    EXPECT_EQ(solution.splitIntoFibonacci("0123"), output);
}
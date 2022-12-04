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

        if (auto it = lookup.find(length); it != lookup.end())
            return it->second;

        int limit = (length + 1) / 2;
        vector<vector<int>> result;
        for (int i = 1; i <= limit; i++)
        {
            int n3 = string2Int(num, length - i, i);
            if (n3 == -1)
                continue;

            for (int j = 1; j < length - i; j++)
            {
                int n1 = string2Int(num, 0, j);
                if (n1 == -1)
                    continue;
                int n2 = string2Int(num, j, length - i - j);
                if (n2 == -1)
                    continue;
                if (n3 - n1 == n2)
                    result.push_back({n1, n2, n3});
            }
            vector<vector<int>> temp = helper(num, length - i);
            for (auto pre : temp)
            {
                if (*(++pre.rbegin()) == n3 - *pre.rbegin())
                {
                    pre.emplace_back(n3);
                    result.emplace_back(pre);
                }
            }
        }
        lookup[length] = result;
        return result;
    }

    int string2Int(string_view num, int begin, int length)
    {
        if (length != 1 and num[begin] == '0')
            return -1;
        if (length > 10)
            return -1;
        try
        {
            return stoi(string(num.substr(begin, length)));
        }
        catch(const std::out_of_range&)
        {
            return -1;
        }
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

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> output = {};
    EXPECT_EQ(solution.splitIntoFibonacci("214748364721474836422147483641"), output);
}
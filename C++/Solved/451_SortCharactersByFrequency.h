#pragma once
#include "Common.h"

class Solution
{
public:
    string frequencySort(const string &s)
    {
        list<pair<int, char>> frequencyList;
        {
            unordered_map<char, int> frequencies;
            for (auto c : s)
            {
                frequencies[c]++;
            }
            for (auto &[c, frequency] : frequencies)
            {
                frequencyList.emplace_back(frequency, c);
            }
        }
        frequencyList.sort([](const pair<int, char> &l, const pair<int, char> &r) {
            return l.first != r.first ? l.first > r.first : l.second > r.second;
        });
        stringstream result;
        for (auto &[frequency, c] : frequencyList)
        {
            result << string(frequency, c);
        }
        return result.str();
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.frequencySort("tree"), "eetr");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.frequencySort("cccaaa"), "cccaaa");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.frequencySort("Aabb"), "bbaA");
}
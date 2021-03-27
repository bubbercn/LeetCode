#pragma once
#include "Common.h"

class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        unordered_set<string> visited;
        visited.emplace(start);
        unordered_set<string> nextLevel;
        nextLevel.emplace(start);
        int result = 0;
        while (!nextLevel.empty())
        {
            unordered_set<string> currentLevel;
            currentLevel.swap(nextLevel);
            for (auto &from : currentLevel)
            {
                for (auto &to : bank)
                {
                    if (visited.count(to) == 0 && isAdjacent(from, to))
                    {
                        nextLevel.emplace(to);
                        visited.emplace(to);
                    }
                }
            }
            result++;
            if (nextLevel.count(end) != 0)
                return result;
        }
        return -1;
    }

private:
    bool isAdjacent(const string &s1, const string &s2)
    {
        int numOfDiff = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                numOfDiff++;
                if (numOfDiff > 1)
                    return false;
            }
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> bank = {"AACCGGTA"};
    EXPECT_EQ(solution.minMutation("AACCGGTT", "AACCGGTA", bank), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    EXPECT_EQ(solution.minMutation("AACCGGTT", "AAACGGTA", bank), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
    EXPECT_EQ(solution.minMutation("AAAAACCC", "AACCCCCC", bank), 3);
}
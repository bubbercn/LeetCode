#pragma once
#include "Common.h"

class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        unordered_map<char, unordered_set<int>> indexLookup;
        ringSize = ring.length();
        for (int i = 0; i < ringSize; i++)
        {
            indexLookup[ring[i]].emplace(i);
        }

        unordered_set<int> froms = {0};
        unordered_map<int, int> currentResult = {{0, 0}};

        for (auto c : key)
        {
            unordered_map<int, int> nextResult;
            const unordered_set<int>& tos = indexLookup.at(c);
            for (auto to : tos)
            {
                for (auto from : froms)
                {
                    int distance = currentResult.at(from) + getDistance(from, to);
                    if (nextResult.count(to) == 0)
                    {
                        nextResult.emplace(to, distance);
                    }
                    else
                    {
                        int& next = nextResult.at(to);
                        next = min(next, distance);
                    }
                }
            }
            swap(currentResult, nextResult);
            froms = tos;
        }

        int result = numeric_limits<int>::max();
        for (auto [index, distance] : currentResult)
        {
            result = min(result, distance);
        }

        return result + key.size();
    }

private:
    int ringSize = 0;
    int getDistance(int from, int to)
    {
        int temp = abs(from - to);
        return min(temp, ringSize - temp);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.findRotateSteps("godding", "gd"), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findRotateSteps("godding", "godding"), 13);
}
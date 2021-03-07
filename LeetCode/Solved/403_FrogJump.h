#pragma once
#include "Common.h"

class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        unordered_map<int, list<int>> curPos;
        unordered_set<int> stoneSet(stones.begin() + 1, stones.end());
        set<pair<int, int>> lookup;
        curPos.emplace(stones[0], list<int>{1});
        while (!curPos.empty())
        {
            unordered_map<int, list<int>> temp;
            for (auto &i : curPos)
            {
                for (auto move : i.second)
                {
                    long to = static_cast<long>(i.first) + move;
                    if (to == *stones.rbegin())
                        return true;
                    if (to > INT_MAX)
                        continue;
                    if (stoneSet.find(to) != stoneSet.end())
                    {
                        if (lookup.emplace(to, move).second)
                        {
                            list<int> &nextMoves = temp[to];
                            if (move - 1 > 0)
                                nextMoves.emplace_back(move - 1);
                            nextMoves.emplace_back(move);
                            nextMoves.emplace_back(move + 1);
                        }
                    }
                }
            }
            swap(curPos, temp);
        }
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    EXPECT_EQ(solution.canCross(stones), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};
    EXPECT_EQ(solution.canCross(stones), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> stones = {0, 1, 3, 6, 10, 13, 15, 18};
    EXPECT_EQ(solution.canCross(stones), true);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> stones = {0, 1, 3, 6, 10, 15, 19, 21, 24, 26, 30, 33};
    EXPECT_EQ(solution.canCross(stones), true);
}

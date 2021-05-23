#pragma once
#include "Common.h"

class Solution
{
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        if (maxChoosableInteger >= desiredTotal)
            return true;

        if (desiredTotal > (maxChoosableInteger + 1) * maxChoosableInteger / 2)
            return false;

        this->desiredTotal = desiredTotal;
        this->maxChoosableInteger = maxChoosableInteger;
        curTotal = 0;
        selected.reset();
        lookup.clear();

        return helper();
    }

private:
    static constexpr int LIMIT = 21;
    bitset<LIMIT> selected;
    unordered_map<bitset<LIMIT>, bool> lookup;
    int maxChoosableInteger;
    int desiredTotal;
    int curTotal;
    bool helper()
    {
        if (auto it = lookup.find(selected); it != lookup.end())
            return it->second;

        int left = desiredTotal - curTotal;
        for (int i = maxChoosableInteger; i > 0; i--)
        {
            if (selected[i])
                continue;

            if (i >= left)
            {
                lookup.emplace(selected, true);
                return true;
            }

            curTotal += i;
            selected.set(i);
            bool next = helper();
            curTotal -= i;
            selected.reset(i);
            if (!next)
            {
                lookup.emplace(selected, true);
                return true;
            }
        }
        lookup.emplace(selected, false);
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
    EXPECT_EQ(solution.canIWin(10, 11), false);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.canIWin(10, 0), true);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.canIWin(10, 1), true);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.canIWin(4,6), true);
}
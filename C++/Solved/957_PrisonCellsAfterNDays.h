#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int n)
    {
        bitset<8> bits;
        unordered_set<int> lookup;
        stack<int> history;
        vector<int> repeat;
        for (int i = 0; i < 8; i++)
        {
            if (cells[i] == 1)
                bits.set(i);
        }
        int i = 0;
        for (; i < n; i++)
        {
            bits = (bits << 1) ^ (bits >> 1);
            bits.flip();
            bits.reset(0);
            bits.reset(7);
            int value = bits.to_ulong();
            if (lookup.emplace(value).second)
            {
                history.emplace(value);
            }
            else
            {
                int temp = 0;
                do
                {
                    temp = history.top();
                    repeat.emplace_back(temp);
                    history.pop();
                } while (temp != value);
                reverse(repeat.begin(), repeat.end());
                break;
            }
        }
        vector<int> result(8);
        if (i != n)
        {
            int m = (n - 1 - i + repeat.size()) % repeat.size();
            bits = bitset<8>(repeat[m]);
        }
        for (int i = 0; i < 8; i++)
        {
            result[i] = bits[i] ? 1 : 0;
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> cells = {0, 1, 0, 1, 1, 0, 0, 1};
    vector<int> output = {0, 0, 1, 1, 0, 0, 0, 0};
    EXPECT_EQ(solution.prisonAfterNDays(cells, 7), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> cells = {1, 0, 0, 1, 0, 0, 1, 0};
    vector<int> output = {0, 0, 1, 1, 1, 1, 1, 0};
    EXPECT_EQ(solution.prisonAfterNDays(cells, 1000000000), output);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size();
        unordered_map<int, int> person2SlotMap;
        unordered_map<int, set<int>> slot2PersonMap;
        for (int i = 0; i < n; i++)
        {
            int slot = i / 2;
            person2SlotMap.emplace(row[i], slot);
            slot2PersonMap[slot].emplace(row[i]);
        }
        vector<bool> visited(n, false);
        int result = 0;
        auto helper = [&](int person)
        {
            unordered_set<int> slots;
            while (true)
            {
                visited[person] = true;
                int slot = person2SlotMap[person];
                int other = person % 2 == 0 ? person + 1 : person - 1;
                visited[other] = true;
                if (slots.emplace(slot).second)
                {
                    set<int>& couple = slot2PersonMap[person2SlotMap[other]] ;
                    person = other == *couple.begin() ? *couple.rbegin() : *couple.begin();
                }
                else
                {
                    break;
                }
            }
            return slots.size() - 1;
        };
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            result += helper(i);
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
    vector<int> row = {0, 2, 1, 3};
    EXPECT_EQ(solution.minSwapsCouples(row), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> row = {3, 2, 0, 1};
    EXPECT_EQ(solution.minSwapsCouples(row), 0);
}
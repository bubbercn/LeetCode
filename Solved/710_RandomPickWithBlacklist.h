#pragma once
#include "Common.h"

class Solution
{
public:
    Solution()
    {
    }

    Solution(int n, const vector<int> &blacklist)
    {
        this->n = n - blacklist.size();
        unordered_set<int> blackSet(blacklist.begin(), blacklist.end());
        int value = n - 1;
        for (auto num : blacklist)
        {
            if (num < this->n)
            {
                while (blackSet.count(value) != 0)
                {
                    value--;
                }
                data.emplace(num, value--);
            }
        }
    }

    int pick()
    {
        int num = rand() % n;
        if (auto it = data.find(num); it != data.end())
            return it->second;
        return num;
    }

private:
    int n;
    unordered_map<int, int> data;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    Solution solution(7, vector<int>({2, 3, 5}));
    solution.pick();
    solution.pick();
    solution.pick();
    solution.pick();
    solution.pick();
    solution.pick();
    solution.pick();
}

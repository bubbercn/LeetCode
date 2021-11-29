#pragma once
#include "Common.h"

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        multimap<int, char, greater<int>> taskMap;
        {
            map<char, int> lookup;
            for (auto task : tasks)
            {
                lookup[task]++;
            }
            for (auto [task, count] : lookup)
            {
                taskMap.emplace(count, task);
            }
        }
        queue<pair<int, char>> cooldownQueue;
        for (int i = 0; i <= n; i++)
        {
            cooldownQueue.emplace(0, '0');
        }
        int result = 0;
        int remain = taskMap.size();
        while (remain > 0)
        {
            auto [count, task] = cooldownQueue.front();
            cooldownQueue.pop();
            if (task != '0')
            {
                taskMap.emplace(count, task);
            }
            if (taskMap.empty())
            {
                cooldownQueue.emplace(0, '0');
            }
            else
            {
                pair<int, char> temp = *taskMap.begin();
                taskMap.erase(taskMap.begin());
                temp.first--;
                if (temp.first == 0)
                {
                    remain--;
                }
                cooldownQueue.emplace(temp);
            }
            result++;
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
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    EXPECT_EQ(solution.leastInterval(tasks, 2), 8);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    EXPECT_EQ(solution.leastInterval(tasks, 0), 6);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    EXPECT_EQ(solution.leastInterval(tasks, 2), 16);
}
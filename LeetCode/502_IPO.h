#pragma once
#include "Common.h"

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        list<Project> projects;
        for (int i = 0; i < profits.size(); i++)
        {
            projects.push_back({profits[i], capital[i]});
        }
        auto cmp = [](const Project &p1, const Project &p2)
        {
            return p1.capital < p2.capital;
        };
        projects.sort(cmp);
        priority_queue<int> profitQ;
        for (int i = 0; i < k; i++)
        {
            for (auto it = projects.begin(); it != projects.end(); it = projects.erase(it))
            {
                if (it->capital > w)
                    break;
                profitQ.emplace(it->profit);
            }
            if (!profitQ.empty())
            {
                w += profitQ.top();
                profitQ.pop();
            }
        }
        return w;
    }

private:
    struct Project
    {
        int profit;
        int capital;
    };
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> profits = {1, 2, 3}, capital = {0, 1, 1};
    EXPECT_EQ(solution.findMaximizedCapital(2, 0, profits, capital), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> profits = {1, 2, 3}, capital = {0, 1, 2};
    EXPECT_EQ(solution.findMaximizedCapital(3, 0, profits, capital), 6);
}

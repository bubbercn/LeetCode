#pragma once
#include "Common.h"

struct Job
{
    int difficulty;
    int profit;
    bool operator < (const Job& another)
    {
        return this->profit < another.profit;
    }
};

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int jobCount = difficulty.size();
        vector<Job> jobs(jobCount);
        for (int i = 0; i < jobCount; i++)
        {
            jobs[i].difficulty = difficulty[i];
            jobs[i].profit = profit[i];
        }
        
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int result = 0;
        for (int i = jobCount - 1; i >= 0 && !worker.empty(); i--)
        {
            auto it = lower_bound(worker.begin(), worker.end(), jobs[i].difficulty);
            result += distance(it, worker.end()) * jobs[i].profit;
            worker.erase(it, worker.end());
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
    vector<int> difficulty = {2, 4, 6, 8, 10};
    vector<int> profit = {10, 20, 30, 40, 50};
    vector<int> worker = {4, 5, 6, 7};
    EXPECT_EQ(solution.maxProfitAssignment(difficulty, profit, worker), 100);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> difficulty = {85, 47, 57};
    vector<int> profit = {24, 66, 99};
    vector<int> worker = {40, 25, 25};
    EXPECT_EQ(solution.maxProfitAssignment(difficulty, profit, worker), 0);
}

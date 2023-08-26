#pragma once
#include "Common.h"

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();
        vector<pair<double, int>> time(n);
        for (int i = 0; i < n; i++)
        {
            time[i].first = static_cast<double>(wage[i]) / quality[i];
            time[i].second = i;
        }
        sort(time.begin(), time.end(), [](const pair<double, int> &v1, const pair<double, int> &v2)
             { return v1.first < v2.first; });

        priority_queue<int, vector<int>> pq;

        int sum = 0;
        double result = numeric_limits<double>::max();
        for (int i = 0; i < n; i++)
        {
            int index = time[i].second;
            if (pq.size() < k)
            {
                pq.emplace(quality[index]);
                sum += quality[index];
            }
            else
            {
                if (quality[index] < pq.top())
                {
                    sum -= pq.top();
                    pq.pop();
                    pq.emplace(quality[index]);
                    sum += quality[index];
                }
            }
            if (pq.size() == k)
            {
                result = min(result, time[i].first * sum);
            }
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
    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    EXPECT_EQ(solution.mincostToHireWorkers(quality, wage, 2), 105);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> quality = {3, 1, 10, 10, 1};
    vector<int> wage = {4, 8, 2, 2, 7};
    EXPECT_EQ(abs(solution.mincostToHireWorkers(quality, wage, 3) - 30.66667) < 1e-5, true);
}
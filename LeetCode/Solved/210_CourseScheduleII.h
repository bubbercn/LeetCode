#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> indegrees(numCourses, 0);
        unordered_map<int, vector<int>> adjacentMap;

        for (const auto &i : prerequisites)
        {
            adjacentMap[i[1]].emplace_back(i[0]);
            indegrees[i[0]]++;
        }

        queue<int> zeroIndegreeQueue;

        for (int i = 0; i < numCourses; i++)
        {
            if (indegrees[i] == 0)
                zeroIndegreeQueue.emplace(i);
        }

        int count = 0;
        vector<int> result;
        result.reserve(numCourses);
        while (!zeroIndegreeQueue.empty())
        {
            int front = zeroIndegreeQueue.front();
            auto it = adjacentMap.find(front);
            if (it != adjacentMap.end())
            {
                for (auto i : it->second)
                {
                    indegrees[i]--;
                    if (indegrees[i] == 0)
                        zeroIndegreeQueue.emplace(i);
                }
            }
            zeroIndegreeQueue.pop();
            result.emplace_back(front);
            count++;
        }

        return count == numCourses ? result : vector<int>();
    }
};

void Test()
{
    Solution solution;
    int numCourses = 0;
    vector<vector<int>> prerequisites;

    numCourses = 2;
    prerequisites = {{1, 0}};
    solution.findOrder(numCourses, prerequisites);
}

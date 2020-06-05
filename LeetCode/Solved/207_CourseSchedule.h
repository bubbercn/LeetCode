#pragma once
#include "Common.h"

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegrees(numCourses, 0);
        unordered_map<int, vector<int>> adjacentMap;

        for (const auto &i : prerequisites)
        {
            adjacentMap[i[0]].emplace_back(i[1]);
            indegrees[i[1]]++;
        }

        queue<int> zeroIndegreeQueue;

        for (int i = 0; i < numCourses; i++)
        {
            if (indegrees[i] == 0)
                zeroIndegreeQueue.emplace(i);
        }

        int result = 0;
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
            result++;
        }

        return result == numCourses;
    }
};

void Test()
{
    Solution solution;
    int numCourses = 0;
    vector<vector<int>> prerequisites;

    numCourses = 2, prerequisites = {{1, 0}};
    assert(solution.canFinish(numCourses, prerequisites));

    numCourses = 2, prerequisites = {{1, 0}, {0, 1}};
    assert(!solution.canFinish(numCourses, prerequisites));
}
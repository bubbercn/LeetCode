#pragma once
#include "Common.h"

class Solution
{
public:
    int containVirus(vector<vector<int>> &isInfected)
    {
        int m = isInfected.size();
        int n = isInfected[0].size();
        int result = 0;

        while (true)
        {
            vector<vector<bool>> isVisited(m, vector<bool>(n, false));
            list<VirusGroup> virusGroups;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (isInfected[i][j] != 1)
                        continue;

                    if (isVisited[i][j])
                        continue;

                    virusGroups.emplace_back(generateVirusGroup({i, j}, isInfected, isVisited));
                }
            }

            if (virusGroups.empty())
                break;

            auto it = max_element(virusGroups.begin(), virusGroups.end(), [](const VirusGroup &g1, const VirusGroup &g2)
                                  { return g1.edges.size() < g2.edges.size(); });

            for (auto [i, j] : it->viruses)
            {
                isInfected[i][j] = -1;
            }
            result += it->edges.size();
            virusGroups.erase(it);
            for (auto &g : virusGroups)
            {
                for (auto [i, j] : g.edges)
                {
                    isInfected[i][j] = 1;
                }
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (isInfected[i][j] != -1)
                        cout << " ";
                    cout << isInfected[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        return result;
    }

private:
    inline static vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    using Virus = pair<int, int>;
    struct VirusGroup
    {
        list<Virus> viruses;
        list<Virus> edges;
    };
    VirusGroup generateVirusGroup(Virus v, vector<vector<int>> &isInfected, vector<vector<bool>> &isVisited)
    {
        VirusGroup result;
        list<Virus> next;
        next.emplace_back(v);
        int m = isInfected.size();
        int n = isInfected[0].size();
        isVisited[v.first][v.second] = true;
        result.viruses.emplace_back(v);
        while (!next.empty())
        {
            list<Virus> temp;
            for (auto [x, y] : next)
            {
                for (auto [dx, dy] : directions)
                {
                    int i = x + dx;
                    int j = y + dy;
                    if (i < 0 || i >= m || j < 0 || j >= n)
                        continue;

                    if (isInfected[i][j] == 1)
                    {
                        if (isVisited[i][j])
                            continue;

                        isVisited[i][j] = true;
                        result.viruses.emplace_back(i, j);
                        temp.emplace_back(i, j);
                    }
                    else if (isInfected[i][j] == 0)
                    {
                        result.edges.emplace_back(i, j);
                    }
                }
            }
            next.swap(temp);
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
    vector<vector<int>> isInfected = {
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };
    EXPECT_EQ(solution.containVirus(isInfected), 10);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> isInfected = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
    };
    EXPECT_EQ(solution.containVirus(isInfected), 4);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> isInfected = {
        {1, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0},
    };
    EXPECT_EQ(solution.containVirus(isInfected), 13);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> isInfected = {
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 1, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 1, 0},
        {0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
    };
    EXPECT_EQ(solution.containVirus(isInfected), 38);
}
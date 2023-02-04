#pragma once
#include "Common.h"

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int x = 0;
        int y = 0;
        int direction = 0;
        unordered_map<int, unordered_set<int>> lookup;
        for (auto &obstacle : obstacles)
        {
            lookup[obstacle[0]].emplace(obstacle[1]);
        }
        int result = 0;
        for (auto command : commands)
        {
            if (command == -2)
            {
                direction += 3;
                direction %= 4;
            }
            else if (command == -1)
            {
                direction++;
                direction %= 4;
            }
            else
            {
                for (int i = 1; i <= command; i++)
                {
                    int nextX = x + directions[direction].first;
                    int nextY = y + directions[direction].second;
                    if (auto it = lookup.find(nextX); it != lookup.end() && it->second.count(nextY) != 0)
                        break;
                    x = nextX;
                    y = nextY;
                    result = max(result, x * x + y * y);
                }
            }
        }
        return result;
    }

private:
    inline static vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> commands = {4, -1, 3};
    vector<vector<int>> obstacles = {};
    EXPECT_EQ(solution.robotSim(commands, obstacles), 25);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> commands = {4, -1, 4, -2, 4};
    vector<vector<int>> obstacles = {{2, 4}};
    EXPECT_EQ(solution.robotSim(commands, obstacles), 65);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> commands = {6, -1, -1, 6};
    vector<vector<int>> obstacles = {};
    EXPECT_EQ(solution.robotSim(commands, obstacles), 36);
}
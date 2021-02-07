#pragma once
#include "Common.h"

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        assert(!heightMap.empty());
        int rowCount = heightMap.size();
        int columnCount = heightMap[0].size();
        vector<vector<bool>> visited(rowCount, vector<bool>(columnCount, false));

        auto cmp = [&heightMap](const pair<int, int> &left, const pair<int, int> &right) {
            return heightMap[left.second][left.second] < heightMap[right.first][right.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);

        auto insertToHeap = [&visited, &heap] (int row, int column) {
            if (!visited[row][column])
            {
                heap.emplace(row, column);
                visited[row][column] = true;
            }
        };

        for (int j = 0; j < columnCount; j++)
        {
            insertToHeap(0, j);
            insertToHeap(rowCount - 1, j);
        }

        for (int i = 0; i < columnCount; i++)
        {
            insertToHeap(i, 0);
            insertToHeap(i, columnCount - 1);
        }

        int result = 0;
        while (!heap.empty())
        {
            
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
    vector<vector<int>> heightMap = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1},
    };
    EXPECT_EQ(solution.trapRainWater(heightMap), 4);
}
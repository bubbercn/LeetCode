#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
            return {};

        int n = matrix.at(0).size();
        if (n == 0)
            return {};

        vector<vector<int>> pointsToPacific = helper(matrix, Ocean::Pacific);
        vector<vector<int>> pointsToAtlantic = helper(matrix, Ocean::Atlantic);
        vector<vector<int>> result(max(pointsToPacific.size(), pointsToAtlantic.size()), vector<int>());
        auto it = set_intersection(pointsToPacific.begin(), pointsToPacific.end(), pointsToAtlantic.begin(), pointsToAtlantic.end(), result.begin());
        result.resize(it - result.begin());
        return result;
    }

private:
    enum class Ocean
    {
        Pacific,
        Atlantic,
    };

    vector<vector<int>> helper(const vector<vector<int>> &matrix, Ocean ocean)
    {
        assert(!matrix.empty());
        int rowCount = matrix.size();
        int columnCount = matrix[0].size();
        vector<vector<bool>> visited(rowCount, vector<bool>(columnCount, false));

        auto cmp = [&matrix](const pair<int, int> &left, const pair<int, int> &right) {
            return matrix[left.first][left.second] == matrix[right.first][right.second] ? left > right : matrix[left.first][left.second] > matrix[right.first][right.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);

        auto insertToHeap = [&visited, &heap](int row, int column) {
            if (!visited[row][column])
            {
                heap.emplace(row, column);
                visited[row][column] = true;
            }
        };

        if (ocean == Ocean::Pacific)
        {
            for (int j = 0; j < columnCount; j++)
            {
                insertToHeap(0, j);
            }

            for (int i = 0; i < rowCount; i++)
            {
                insertToHeap(i, 0);
            }
        }
        else
        {
            for (int j = 0; j < columnCount; j++)
            {
                insertToHeap(rowCount - 1, j);
            }

            for (int i = 0; i < rowCount; i++)
            {
                insertToHeap(i, columnCount - 1);
            }
        }

        auto tryInsertNeighbour = [&](const pair<int, int> &p, const pair<int, int> &np) {
            if (np.first >= 0 && np.first < rowCount && np.second >= 0 && np.second < columnCount && !visited[np.first][np.second])
            {
                if (matrix[np.first][np.second] >= matrix[p.first][p.second])
                {
                    heap.emplace(np);
                    visited[np.first][np.second] = true;
                }
            }
        };

        while (!heap.empty())
        {
            auto top = heap.top();
            heap.pop();
            tryInsertNeighbour(top, {top.first - 1, top.second});
            tryInsertNeighbour(top, {top.first + 1, top.second});
            tryInsertNeighbour(top, {top.first, top.second - 1});
            tryInsertNeighbour(top, {top.first, top.second + 1});
        }

        vector<vector<int>> result;
        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                if (visited[i][j])
                {
                    result.push_back({i, j});
                }
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

TEST_F(LeetCodeTest, Example)
{
    vector<vector<int>> matrix = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4},
    };
    vector<vector<int>> output = {
        {0, 4},
        {1, 3},
        {1, 4},
        {2, 2},
        {3, 0},
        {3, 1},
        {4, 0},
    };
    EXPECT_EQ(solution.pacificAtlantic(matrix), output);
}
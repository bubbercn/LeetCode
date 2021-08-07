#pragma once
#include "Common.h"

class Solution
{
public:
    Solution()
    {
    }

    Solution(vector<vector<int>> &rects)
    {
        this->rects = rects;
        for (int i = 0; i < rects.size(); i++)
        {
            this->rects[i].emplace_back(size);
            size += (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            this->rects[i].emplace_back(size);
        }
    }

    vector<int> pick()
    {
        int value = rand() % size;
        int index = find(value);
        int offset = value - rects[index][4];
        int offsetY = offset / (rects[index][2] - rects[index][0] + 1);
        int offsetX = offset - offsetY * (rects[index][2] - rects[index][0] + 1);
        return {rects[index][0] + offsetX, rects[index][1] + offsetY};
    }

private:
    int size = 0;
    vector<vector<int>> rects;
    int find(int value)
    {
        int left = 0;
        int right = rects.size();
        while (left < right)
        {
            int middle = (left + right) / 2;
            if (value < rects[middle][4])
            {
                right = middle;
            }
            else if (value >= rects[middle][5])
            {
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        assert(false);
        return -1;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> rects{{-2, -2, 1, 1}, {2, 2, 4, 6}};
    Solution temp(rects);
    while (true)
    {
        auto value = temp.pick();
        cout << value[0] << ", " << value[1] << endl;
    }
}
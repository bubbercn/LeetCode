#pragma once
#include "Common.h"

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        return larget(heights, 0, heights.size() - 1);
    }

private:
    int largetMiddle(vector<int> &heights, int left, int right, int middle)
    {
        int area = heights[middle];
        int width = 1;
        int height = area;
        int i = middle, j = middle;
        while (true)
        {
            if (i - 1 >= left)
            {
                if (j + 1 <= right)
                {
                    if (heights[i - 1] > heights[j + 1])
                    {
                        i--;
                        height = min(height, heights[i]);
                        width++;
                        area = max(area, height * width);
                    }
                    else
                    {
                        j++;
                        height = min(height, heights[j]);
                        width++;
                        area = max(area, height * width);
                    }
                }
                else
                {
                    i--;
                    height = min(height, heights[i]);
                    width++;
                    area = max(area, height * width);
                }
            }
            else
            {
                if (j + 1 <= right)
                {
                    j++;
                    height = min(height, heights[j]);
                    width++;
                    area = max(area, height * width);
                }
                else
                {
                    break;
                }
            }
        }

        return area;
    }
    int larget(vector<int> &heights, int left, int right)
    {
        if (left > right)
        {
            return 0;
        }
        else if (left == right)
        {
            return heights[left];
        }
        else
        {
            int middle = (left + right) / 2;
            return max(largetMiddle(heights, left, right, middle),
                       max(larget(heights, left, middle - 1), larget(heights, middle + 1, right)));
        }
    }
};

void Test()
{
    Solution solution;
    vector<int> input = {2, 1, 5, 6, 2, 3};
    assert(solution.largestRectangleArea(input) == 10);
}
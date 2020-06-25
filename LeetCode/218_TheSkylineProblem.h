#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> skyLines;
        for (int i = 0; i < buildings.size(); i++)
        {
            if (i == 0 || buildings[i][0] > buildings[i - 1][1])
            {
                vector<int> skyLine(3);
                skyLine[0] = buildings[i][0];
                skyLine[1] = -1;
                skyLine[2] = buildings[i][2];
                skyLines.emplace_back(skyLine);
            }
            else
            {
                if (buildings[i][2] > buildings[i - 1][2] && buildings[i][0] <= buildings[i - 1][1])
                {
                    (*skyLines.rbegin())[1] = buildings[i][0];
                    vector<int> skyLine(3);
                    skyLine[0] = buildings[i][0];
                    skyLine[1] = -1;
                    skyLine[2] = buildings[i][2];
                    skyLines.emplace_back(skyLine);
                }
            }
        }

        // sort buildings by r

        // scan building from right
    }
};

void Test()
{
}
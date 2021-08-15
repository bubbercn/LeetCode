#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        enum class Direction
        {
            IN,
            OUT
        };
        
        struct Action
        {
            Action(int p, int h, Direction d) : pos(p), height(h), direction(d)
            {
                
            }
            int pos;
            int height;
            Direction direction;
            void Do(multiset<int>& heights)
            {
                if (direction == Direction::IN)
                {
                    heights.emplace(height);
                }
                else
                {
                    auto temp = heights.find(height);
                    heights.erase(temp);
                }
            }
        };
        
        vector<Action> actions;
        for (const auto& building : buildings)
        {
            actions.emplace_back(building[0], building[2], Direction::IN);
            actions.emplace_back(building[1], building[2], Direction::OUT);
        }
        
        sort(actions.begin(), actions.end(), [](const Action& a1, const Action& a2)->bool{ return a1.pos < a2.pos;});
        
        int curHeight = -1;
        multiset<int> heights;
        vector<vector<int>> result;
        for (int i = 0; i < actions.size();)
        {
            int curPos = actions[i].pos;
            while (i < actions.size())
            {
                if (i == 0)
                {
                    actions[i++].Do(heights);
                }
                else if (actions[i].pos == curPos)
                {
                    actions[i++].Do(heights);
                }
                else
                {
                    break;
                }
            }
            if (curHeight == -1)
            {
                result.push_back({curPos, *heights.rbegin()});
                curHeight = *heights.rbegin();
            }
            else if (heights.empty())
            {
                result.push_back({curPos, 0});
                curHeight = 0;
            }
            else if (curHeight != *heights.rbegin())
            {
                result.push_back({curPos, *heights.rbegin()});
                curHeight = *heights.rbegin();
            }
        }
        
        return result;
    }
};

void Test()
{
    Solution solution;
    //    vector<vector<int>> buildings = {
    //        {2, 9, 10},
    //        {3, 7, 15},
    //        {5, 12, 12},
    //        {15, 20, 10},
    //        {19, 24, 8},
    //    };
    
    //    vector<vector<int>> buildings = {
    //        {0, 2, 3},
    //        {2, 5, 3},
    //    };
    
    //    vector<vector<int>> buildings = {
    //        {1,2,1},
    //        {1,2,2},
    //        {1,2,3}
    //    };
    
    vector<vector<int>> buildings = {
        {0,3,3},
        {1,5,3},
        {2,4,3},
        {3,7,3}
    };
    
    //    vector<vector<int>> buildings = {
    //        {0,5,7},{5,10,7},{5,10,12},{10,15,7},{15,20,7},{15,20,12},{20,25,7}
    //    };
    
    solution.getSkyline(buildings);
}

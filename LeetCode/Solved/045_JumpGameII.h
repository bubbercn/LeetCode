#pragma once
#include "Common.h"

class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        size_t steps = 0;
        size_t size = nums.size();
        size_t cur = 0;
        size_t i = 0;
        while (cur < size - 1) {
            steps++;
            size_t pre = cur;
            while (i <= pre)
            {
                if (i + nums[i] > cur)
                {
                    cur = i + nums[i];
                }
                i++;
            }
            if (pre == cur) return -1; // May not need this
        }
        return steps;
    }
};

// class Solution
// {
// public:
//     int jump(vector<int>& nums)
//     {
//         vector<size_t> distance;
//         size_t size = nums.size();
//         distance.assign(size, -1);

//         distance[0] = 0;

//         for (size_t i = 0; i < size; i++)
//         {
//             for (size_t j = 1; j <= nums[i] && i + j < size; j++)
//             {
//                 if (distance[i] + 1 < distance[i + j])
//                 {
//                     distance[i + j] = distance[i] + 1;
//                     if (i + j == size - 1)
//                         return distance[i + j];
//                 }
//             }
//         }

//         return static_cast<int>(distance[size - 1]);
//     }
// };


void Test()
{
    Solution solution;
    vector<int> input = {2, 3, 1, 1, 4};
    assert(solution.jump(input) == 2);
    
    input = {2};
    assert(solution.jump(input) == 0);

    input = {1, 1, 1, 1};
    assert(solution.jump(input) == 3);
}


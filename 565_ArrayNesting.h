#pragma once
#include "Common.h"

class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        unordered_map<int, int> paths;
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == -1)
                continue;
            
            int start = i;
            int length = 0;
            int next = start;
            while (nums[next] != -1)
            {
                length++;
                int &temp = nums[next];
                next = nums[next];
                temp = -1;
            }
            if (start != next)
            {
                length += paths.at(nums[next]);
                paths.erase(nums[next]);
            }
            paths.emplace(start, length);
            result = max(result, length);
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
    vector<int> nums = {5, 4, 0, 3, 1, 6, 2};
    EXPECT_EQ(solution.arrayNesting(nums), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0, 1, 2};
    EXPECT_EQ(solution.arrayNesting(nums), 1);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int result = 0;
        map<int, int> lookup;
        for (int i = 0; i < nums.size(); i++)
        {
            if (lookup.empty() || nums[i] < lookup.begin()->first)
            {
                lookup.emplace(nums[i], i);
            }
            else
            {
                int left = -1;
                if (auto it = lookup.lower_bound(nums[i]); it->first == nums[i])
                {
                    left = it->second;
                }
                else
                {
                    left = (--it)->second;
                }
                result = max(result, i - left);
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

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {6, 0, 8, 2, 1, 5};
    EXPECT_EQ(solution.maxWidthRamp(nums), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    EXPECT_EQ(solution.maxWidthRamp(nums), 7);
}

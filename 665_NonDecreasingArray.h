#pragma once
#include "Common.h"

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        vector<pair<int, int>> sequences(2);
        int index = 0;
        int begin = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] >= nums[i - 1])
                continue;
            
            sequences[index] = {begin, i};
            begin = i;
            index++;
            if (index > 1)
                return false;
        }
        
        if (index == 0)
            return true;

        sequences[index] = {begin, n};
        if (sequences[0].second - sequences[0].first == 1 || sequences[1].second - sequences[1].first == 1)
            return true;
        
        if (nums[sequences[0].second - 2] <= nums[sequences[1].first] || nums[sequences[0].second - 1] <= nums[sequences[1].first + 1])
            return true;

        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {4, 2, 3};
    EXPECT_EQ(solution.checkPossibility(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {4, 2, 1};
    EXPECT_EQ(solution.checkPossibility(nums), false);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    Solution(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            lookup[nums[i]].emplace_back(i);
        }
    }

    int pick(int target)
    {
        vector<int> &v = lookup[target]; 
        return v[random() % v.size()];
    }
private:
    unordered_map<int, vector<int>> lookup;
};

class LeetCodeTest : public testing::Test
{
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 2, 3, 3, 3};
    Solution solution(nums);
    EXPECT_PRED1([](int val) { return val == 2 || val == 3 || val == 4; }, solution.pick(3));
    EXPECT_EQ(solution.pick(1), 0);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        int n = nums.size();
        list<int> even;
        list<int> odd;
        for (int i = 0; i < n; i++)
        {
            if ((i & 1) == (nums[i] & 1))
                continue;

            if ((i & 1) == 0)
            {
                even.emplace_back(i);
            }
            else
            {
                odd.emplace_back(i);
            }
        }
        for (auto i = even.begin(), j = odd.begin(); i != even.end(); i++, j++)
        {
            swap(nums[*i], nums[*j]);
        }
        return nums;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {4, 2, 5, 7};
    vector<int> output = {4, 5, 2, 7};
    EXPECT_EQ(solution.sortArrayByParityII(nums), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 3};
    vector<int> output = {2, 3};
    EXPECT_EQ(solution.sortArrayByParityII(nums), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {2, 3, 1, 1, 4, 0, 0, 4, 3, 3};
    vector<int> output = {2, 3, 0, 1, 4, 1, 0, 3, 4, 3};
    EXPECT_EQ(solution.sortArrayByParityII(nums), output);
}
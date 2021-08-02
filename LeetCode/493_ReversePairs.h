#pragma once
#include "Common.h"

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        return helper(nums, 0, nums.size());
    }

private:
    int helper(vector<int> &nums, int left, int right)
    {
        if (left + 1 == right)
        {
            return 0;
        }
        else
        {
            int middle = (left + right) / 2;
            int result = helper(nums, left, middle) + helper(nums, middle, right);

            int j = middle;
            for (int i = left; i < middle; i++)
            {
                while (j < right)
                {
                    if (static_cast<long>(nums[i]) <= 2 * (static_cast<long>(nums[j])))
                    {
                        break;
                    }
                    j++;
                }
                result += j - middle;
            }

            vector<int> temp(right - left);
            int p1 = left;
            int p2 = middle;
            int p = 0;
            while (p1 < middle || p2 < right)
            {
                if (p1 == middle)
                {
                    temp[p++] = nums[p2++];
                }
                else if (p2 == right)
                {
                    temp[p++] = nums[p1++];
                }
                else
                {
                    if (nums[p1] < nums[p2])
                    {
                        temp[p++] = nums[p1++];
                    }
                    else
                    {
                        temp[p++] = nums[p2++];
                    }
                }
            }
            for (int i = 0; i < temp.size(); i++)
            {
                nums[left + i] = temp[i];
            }
            return result;
        }
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 3, 2, 3, 1};
    EXPECT_EQ(solution.reversePairs(nums), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 4, 3, 5, 1};
    EXPECT_EQ(solution.reversePairs(nums), 3);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {2147483647, 2147483647, -2147483647, -2147483647, -2147483647, 2147483647};
    EXPECT_EQ(solution.reversePairs(nums), 9);
}
#pragma once
#include "Common.h"

// class NumArray
// {
// public:
//     NumArray(vector<int> &nums)
//     {
//         this->nums = move(nums);
//     }

//     void update(int i, int val)
//     {
//         nums[i] = val;
//     }

//     int sumRange(int i, int j)
//     {
//         int sum = 0;
//         for (int k = i; k <= j; k++)
//         {
//             sum += nums[k];
//         }
//         return sum;
//     }

// private:
//     vector<int> nums;
// };

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        binaryTree = vector<int>(n * 2);
        for (int i = 0; i < n; i++)
        {
            binaryTree[i + n] = nums[i];
        }
        for (int i = n - 1; i > 0; i--)
        {
            binaryTree[i] = binaryTree[i * 2] + binaryTree[i * 2 + 1];
        }
    }

    void update(int i, int val)
    {
        int index = i + binaryTree.size() / 2;
        int delta = val - binaryTree[index];
        while (index > 0)
        {
            binaryTree[index] += delta;
            index /= 2;
        }
    }

    int sumRange(int i, int j)
    {
        int n = binaryTree.size() / 2;
        int left = n + i;
        int right = n + j;
        int sum = 0;
        while (left <= right)
        {
            if (left % 2 == 1)
            {
                sum += binaryTree[left];
                left++;
            }
            if (right % 2 == 0)
            {
                sum += binaryTree[right];
                right--;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }

private:
    vector<int> binaryTree;
};

class Solution
{
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 3, 5};
    unique_ptr<NumArray> obj(new NumArray(nums));

    EXPECT_EQ(obj->sumRange(0, 2), 9);

    obj->update(1, 2);

    EXPECT_EQ(obj->sumRange(0, 2), 8);
}
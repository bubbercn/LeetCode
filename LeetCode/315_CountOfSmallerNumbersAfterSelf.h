#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        set<int> uniqueNums(nums.begin(), nums.end());

        map<int, int> keyToIndex;
        int index = 0;
        for (auto &i : uniqueNums)
        {
            keyToIndex[i] = index++;
        }

        NumArray numArray(vector<int>(uniqueNums.size(), 0));
        vector<int> result(nums.size(), 0);

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int index = keyToIndex[nums[i]];
            numArray.update(index, 1);
            if (i != nums.size() - 1)
            {
                result[i] = numArray.sumRange(0, index - 1);
            }
        }

        return result;
    }

private:
    class NumArray
    {
    public:
        NumArray(const vector<int> &nums)
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

        void update(int i, int delta)
        {
            int index = i + binaryTree.size() / 2;
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
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {5, 2, 6, 1};
    vector<int> output = {2, 1, 1, 0};
    EXPECT_EQ(solution.countSmaller(nums), output);
}

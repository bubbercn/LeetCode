#pragma once
#include "Common.h"

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        if (nums.empty())
            return;

        auto median = nums.begin() + nums.size() / 2;

        nth_element(nums.begin(), median, nums.end());

        partition(nums, *median);

        if (nums.size() % 2)
            median++;

        reverse(nums.begin(), median);
        reverse(median, nums.end());

        int middle = median - nums.begin();
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            int newIndex = getNewIndex(i, middle);
            result[newIndex] = nums[i];
        }
        swap(result, nums);
    }

private:
    void partition(vector<int> &nums, int median)
    {
        auto left = nums.begin();
        auto right = nums.end() - 1;
        for (auto i = left; i <= right; i++)
        {
            if (*i < median)
            {
                swap(*i, *left++);
            }
            else if (*i > median)
            {
                swap(*i, *right--);
            }
        }
    }
    int getNewIndex(int index, int median)
    {
        if (index < median)
        {
            return index * 2;
        }
        else
        {
            return (index - median) * 2 + 1;
        }
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

void check(const vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0 && i + 1 < nums.size())
        {
            EXPECT_LT(nums[i], nums[i + 1]);
        }
        if (i % 2 != 0 && i + 1 < nums.size())
        {
            EXPECT_GT(nums[i], nums[i + 1]);
        }
    }
}

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 5, 1, 1, 6, 4};
    solution.wiggleSort(nums);
    check(nums);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 3, 2, 2, 3, 1};
    solution.wiggleSort(nums);
    check(nums);
}

TEST_F(LeetCodeTest, Case1)
{
    vector<int> nums = {1, 2, 4, 4, 4, 6, 7};
    solution.wiggleSort(nums);
    check(nums);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {1, 2, 1, 2, 1, 1, 2, 2, 1};
    solution.wiggleSort(nums);
    check(nums);
}

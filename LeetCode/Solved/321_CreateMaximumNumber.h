#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<int> result(k, 0);
        int m = nums1.size();
        int n = nums2.size();

        for (int i = max(k - n, 0); i <= min(m, k); i++)
        {
            list<int> maxNumber1 = getMaxNumList(nums1, i);
            list<int> maxNumber2 = getMaxNumList(nums2, k - i);
            vector<int> temp = mergeLists(maxNumber1, maxNumber2);
            if (temp > result)
            {
                swap(temp, result);
            }
        }

        return result;
    }

private:
    list<int> getMaxNumList(const vector<int> &nums, int k)
    {
        list<int> result;
        for (size_t i = 0; i < nums.size(); i++)
        {
            while (!result.empty() && nums[i] > result.back() && k - result.size() < nums.size() - i)
            {
                result.pop_back();
            }
            if (static_cast<int>(result.size()) < k)
            {
                result.emplace_back(nums[i]);
            }
        }
        return result;
    }
    vector<int> mergeLists(const list<int> &list1, const list<int> &list2)
    {
        vector<int> result(list1.size() + list2.size());
        auto i = list1.begin(), j = list2.begin();
        int index = 0;
        while (i != list1.end() || j != list2.end())
        {
            result[index++] = lexicographical_compare(i, list1.end(), j, list2.end()) ? *j++ : *i++;
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums1 = {3, 4, 6, 5};
    vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    vector<int> output = {9, 8, 6, 5, 3};
    EXPECT_EQ(solution.maxNumber(nums1, nums2, 5), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums1 = {6, 7};
    vector<int> nums2 = {6, 0, 4};
    vector<int> output = {6, 7, 6, 0, 4};
    EXPECT_EQ(solution.maxNumber(nums1, nums2, 5), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums1 = {3, 9};
    vector<int> nums2 = {8, 9};
    vector<int> output = {9, 8, 9};
    EXPECT_EQ(solution.maxNumber(nums1, nums2, 3), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums1 = {7, 6, 1, 9, 3, 2, 3, 1, 1};
    vector<int> nums2 = {4, 0, 9, 9, 0, 5, 5, 4, 7};
    vector<int> output = {9, 9, 9, 7, 3, 2, 3, 1, 1};
    EXPECT_EQ(solution.maxNumber(nums1, nums2, 9), output);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> nums1 = {2, 5, 6, 4, 4, 0};
    vector<int> nums2 = {7, 3, 8, 0, 6, 5, 7, 6, 2};
    vector<int> output = {7, 3, 8, 2, 5, 6, 4, 4, 0, 6, 5, 7, 6, 2, 0};
    EXPECT_EQ(solution.maxNumber(nums1, nums2, 15), output);
}
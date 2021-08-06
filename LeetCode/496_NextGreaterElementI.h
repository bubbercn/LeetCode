#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> indexLookup;
        unordered_map<int, int> index2NextGreaterElement;
        stack<int> temp;
        for (int i = 0; i < nums2.size(); i++)
        {
            while (!temp.empty() && nums2[i] > nums2[temp.top()])
            {
                index2NextGreaterElement.emplace(temp.top(), nums2[i]);
                temp.pop();
            }
            temp.emplace(i);
            indexLookup.emplace(nums2[i], i);
        }
        while (!temp.empty())
        {
            index2NextGreaterElement.emplace(temp.top(), -1);
            temp.pop();
        }
        vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); i++)
        {
            result[i] = index2NextGreaterElement.at(indexLookup.at(nums1[i]));
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
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> output = {-1, 3, -1};
    EXPECT_EQ(solution.nextGreaterElement(nums1, nums2), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> output = {3, -1};
    EXPECT_EQ(solution.nextGreaterElement(nums1, nums2), output);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        bool swapped = false;
        if (nums1.size() > nums2.size())
        {
            nums1.swap(nums2);
            swapped = true;
        }
        priority_queue<Item, vector<Item>, ItemCompare> pQueue;

        if (!nums2.empty())
        {
            for (auto i : nums1)
            {
                pQueue.push({i, {nums2[0], 0}});
            }
        }

        vector<vector<int>> result;
        for (int i = 0; i < k && !pQueue.empty(); i++)
        {
            if (swapped)
            {
                result.push_back({pQueue.top().second.first, pQueue.top().first});
            }
            else
            {
                result.push_back({pQueue.top().first, pQueue.top().second.first});
            }
            auto temp = pQueue.top();
            pQueue.pop();
            if (temp.second.second + 1 < nums2.size())
            {
                int first = temp.first;
                int second = temp.second.second + 1;
                pQueue.push({first, {nums2[second], second}});
            }
        }

        return result;
    }

private:
    using Item = pair<int, pair<int, int>>;
    class ItemCompare
    {
    public:
        bool operator()(const Item &lhs, const Item &rhs)
        {
            return lhs.first + lhs.second.first > rhs.first + rhs.second.first;
        }
    };
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    vector<vector<int>> output = {{1, 2}, {1, 4}, {1, 6}};
    EXPECT_EQ(solution.kSmallestPairs(nums1, nums2, 3), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {1, 2, 3};
    vector<vector<int>> output = {{1, 1}, {1, 1}};
    EXPECT_EQ(solution.kSmallestPairs(nums1, nums2, 2), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3};
    vector<vector<int>> output = {{1, 3}, {2, 3}};
    EXPECT_EQ(solution.kSmallestPairs(nums1, nums2, 3), output);
}
#pragma once
#include "Common.h"

class Solution
{
public:
    int numComponents(ListNode *head, vector<int> &nums)
    {
        unordered_set<int> lookup;
        for (auto num : nums)
        {
            lookup.emplace(num);
        }
        bool begin = false;
        ListNode *node = head;
        int result = 0;
        while (node)
        {
            if (lookup.count(node->val) == 0)
            {
                if (begin)
                {
                    result++;
                    begin = false;
                }
            }
            else if (!begin)
            {
                begin = true;
            }
            node = node->next;
        }
        if (begin)
            result++;
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
    vector<int> values = {0, 1, 2, 3};
    vector<unique_ptr<ListNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new ListNode(*i));
    }
    for (int i = 0; i < nodes.size() - 1; i++)
    {
        nodes[i]->next = nodes[i + 1].get();
    }
    vector<int> nums = {0, 1, 3};
    EXPECT_EQ(solution.numComponents(nodes[0].get(), nums), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> values = {0, 1, 2, 3, 4};
    vector<unique_ptr<ListNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new ListNode(*i));
    }
    for (int i = 0; i < nodes.size() - 1; i++)
    {
        nodes[i]->next = nodes[i + 1].get();
    }
    vector<int> nums = {0, 3, 1, 4};
    EXPECT_EQ(solution.numComponents(nodes[0].get(), nums), 2);
}
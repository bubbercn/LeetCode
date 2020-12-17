#pragma once
#include "Common.h"

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head)
    {
        list<int> valueList;
        while (head != nullptr)
        {
            valueList.emplace_back(head->val);
            head = head->next;
        }
        values.reserve(valueList.size());
        for (auto i : valueList)
        {
            values.emplace_back(i);
        }
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        uniform_int_distribution<> distrib(0, values.size() - 1);
        return values[distrib(gen)];
    }

private:
    vector<int> values;
    random_device rd;
};

class LeetCodeTest : public testing::Test
{
};
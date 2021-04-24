#pragma once
#include "Common.h"

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int length1 = getLength(l1);
        int length2 = getLength(l2);
        int delta = abs(length1 - length2);
        ListNode *result = length1 > length2 ? l1 : l2;
        ListNode *node1 = result;
        ListNode *node2 = length2 <= length1 ? l2 : l1;
        for (int i = 0; i < delta; i++)
        {
            node1 = node1->next;
        }

        while (node1 != nullptr)
        {
            node1->val += node2->val;
            node1 = node1->next;
            node2 = node2->next;
        }

        return result;
    }

private:
    int getLength(ListNode *l)
    {
        int result = 0;
        while (l != nullptr)
        {
            result++;
            l = l->next;
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};


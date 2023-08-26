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
        ListNode *node2 = length1 <= length2 ? l1 : l2;
        for (int i = 0; i < delta; i++)
        {
            node1 = node1->next;
        }
        int temp = helper(result, node1, helper(node1, node2));
        if (temp > 0)
        {
            ListNode *head = new ListNode(temp);
            head->next = result;
            result = head;
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
    int helper(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return 0;
        int temp = helper(l1->next, l2->next);
        temp += l1->val + l2->val;
        l1->val = temp % 10;
        return temp /= 10;
    }
    int helper(ListNode *begin, ListNode *end, int val)
    {
        if (begin == end)
            return val;

        if (begin->next == end)
        {
            begin->val += val;
            int temp = begin->val / 10;
            begin->val = begin->val % 10;
            return temp;
        }

        int temp = helper(begin->next, end, val);
        temp += begin->val;
        begin->val = temp % 10;
        return temp / 10;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

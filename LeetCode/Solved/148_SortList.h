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
    ListNode* sortList(ListNode* head)
    {
        if (head == nullptr)
            return nullptr;
        
        ListNode* pivot = pickNode(head);
        ListNode left(0), right(0);
        
        ListNode* node = head;
        while (node != nullptr)
        {
            ListNode* temp = node->next;
            if (node == pivot)
            {
                
            }
            else if (node->val < pivot->val)
            {
                insert(&left, node);
            }
            else
            {
                insert(&right, node);
            }
            node = temp;
        }
        
        left.next = sortList(left.next);
        right.next = sortList(right.next);
        
        ListNode* result = nullptr;
        if (left.next != nullptr)
        {
            result = left.next;
            node = result;
            while (node->next != nullptr)
            {
                node = node->next;
            }
            node->next = pivot;
        }
        else
        {
            result = pivot;
        }
        
        pivot->next = right.next;
        
        return result;
    }
private:
    inline ListNode* pickNode(ListNode* head)
    {
//        ListNode* fast = head, * slow = head;
//        while (true)
//        {
//            fast = fast->next;
//            if (fast == nullptr)
//                break;
//            fast = fast->next;
//            if (fast == nullptr)
//                break;
//            slow = slow->next;
//        }
//        return slow;
        return head;
    }
    inline void insert(ListNode* head, ListNode* node)
    {
        node->next = head->next;
        head->next = node;
    }
};

void Test()
{
    Solution solution;
    
    vector<int> values = {1, 2, 3, 4};
    vector<unique_ptr<ListNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new ListNode(*i));
    }
    nodes[3]->next = nodes[1].get();
    nodes[1]->next = nodes[0].get();
    nodes[0]->next = nodes[2].get();
    
    solution.sortList(nodes[3].get());
}

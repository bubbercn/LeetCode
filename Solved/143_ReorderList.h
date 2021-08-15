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
    void reorderList(ListNode* head)
    {
        if (head == nullptr)
            return;
        
        list<ListNode*> nodeList;
        ListNode* temp = head->next;
        while (temp != nullptr)
        {
            nodeList.emplace_back(temp);
            temp = temp->next;
        }
        
        temp = head;
        while (true)
        {
            if (!nodeList.empty())
            {
                temp->next = nodeList.back();
                temp = temp->next;
                nodeList.pop_back();
            }
            else
            {
                temp->next = nullptr;
                break;
            }
            
            if (!nodeList.empty())
            {
                temp->next = nodeList.front();
                temp = temp->next;
                nodeList.pop_front();
            }
            else
            {
                temp->next = nullptr;
                break;
            }
        }
    }
};

void Test()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = nullptr;
    
    Solution solution;
    solution.reorderList(&node1);
}

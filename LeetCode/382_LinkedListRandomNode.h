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
    }

    /** Returns a random node's value. */
    int getRandom()
    {
    }
};

class LeetCodeTest : public testing::Test
{
    
};
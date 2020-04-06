#pragma once
#include "Common.h"

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        vector<int> nums;
        while (head != nullptr)
        {
            nums.emplace_back(head->val);
            head = head->next;
        }
        
        if (nums.empty())
            return nullptr;
        
        return helper(nums, 0, nums.size());
    }
private:
    TreeNode* helper(vector<int>& nums, size_t begin, size_t end)
    {
        size_t middle = (begin + end) / 2;
        TreeNode* root = new TreeNode(nums[middle]);
        
        root->left = middle > begin ? helper(nums, begin, middle) : nullptr;
        root->right = middle + 1 < end ? helper(nums, middle + 1, end) : nullptr;
        
        return root;
    }
};

void Test()
{
    
}

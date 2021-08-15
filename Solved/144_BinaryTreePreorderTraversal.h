#pragma once
#include "Common.h"

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
    vector<int> preorderTraversal(TreeNode* root)
    {
        list<int> result;
        stack<TreeNode*> nodeStack;
        nodeStack.emplace(root);
        
        while (!nodeStack.empty())
        {
            TreeNode* temp = nodeStack.top();
            nodeStack.pop();
            if (temp)
            {
                result.emplace_back(temp->val);
                nodeStack.emplace(temp->right);
                nodeStack.emplace(temp->left);
            }
        }
        
        return {result.begin(), result.end()};
    }
};

void Test()
{
    
}

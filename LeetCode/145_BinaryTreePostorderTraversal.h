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
    vector<int> postorderTraversal(TreeNode* root)
    {
        list<int> result;
        stack<TreeNode*> nodeStack;
        if (root)
        {
            nodeStack.emplace(root);
        }
        
        TreeNode* lastNode = nullptr;
        while (!nodeStack.empty())
        {
            TreeNode* temp = nodeStack.top();
            
            if (temp->left == nullptr && temp->right == nullptr)
            {
                result.emplace_back(temp->val);
                lastNode = temp;
                nodeStack.pop();
                continue;
            }
            
            if (lastNode && (temp->left == lastNode || temp->right == lastNode))
            {
                result.emplace_back(temp->val);
                lastNode = temp;
                nodeStack.pop();
                continue;
            }
            
            if (temp->right)
            {
                nodeStack.emplace(temp->right);
            }
            
            if (temp->left)
            {
                nodeStack.emplace(temp->left);
            }
        }
        
        return {result.begin(), result.end()};
    }
};

void Test()
{
    Solution solution;
    
    vector<int> values = {1, 2, 3};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->right = nodes[1].get();
    nodes[1]->left = nodes[2].get();
    
    solution.postorderTraversal(nodes[0].get());
}

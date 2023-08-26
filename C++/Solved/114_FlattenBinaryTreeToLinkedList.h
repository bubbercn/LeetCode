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
    void flatten(TreeNode* root) 
    {
        helper(root);
    }
private:
    TreeNode* helper(TreeNode* root)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode* leftTail = helper(root->left);
        TreeNode* rightTail = helper(root->right);

        if (leftTail == nullptr && rightTail == nullptr)
        {
            return root;
        }

        if (leftTail != nullptr)
        {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            if (rightTail ==  nullptr)
            {
                return leftTail;
            }
            else
            {
                return rightTail;
            }
        }
        else
        {
            return rightTail;
        }
    }
};

void Test()
{
    Solution solution;
    
    vector<int> values = {1, 2, 5, 3, 4, 6};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    nodes[1]->left = nodes[3].get();
    nodes[1]->right = nodes[4].get();
    nodes[2]->right = nodes[5].get();
    
    solution.flatten(nodes[0].get());
}
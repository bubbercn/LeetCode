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
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
            
        vector<int> result;
        stack<TreeNode *> remaining;
        remaining.push(root);
        bool pop = false;
        while (!remaining.empty())
        {
            TreeNode *current = remaining.top();
            if (current->left != nullptr && !pop)
            {
                remaining.emplace(current->left);
                pop = false;
            }
            else
            {
                result.emplace_back(current->val);
                remaining.pop();
                pop = true;
                if (current->right != nullptr)
                {
                    remaining.emplace(current->right);
                    pop = false;
                }
            }
        }
        return result;
    }
};

void Test()
{
    vector<int> values = {1, 2, 3};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->right = nodes[1].get();
    nodes[1]->left = nodes[2].get();
    Solution solution;
    solution.inorderTraversal(nodes[0].get());
}
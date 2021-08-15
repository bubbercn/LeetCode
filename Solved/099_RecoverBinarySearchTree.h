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
    void recoverTree(TreeNode* root)
    {
        inorderTraversal(root);
        if (!node2)
            node2 = preNode;
        swap(node1->val, node2->val);
    }
private:
    bool inorderTraversal(TreeNode* root)
    {
        if (!root)
            return true;
        
        if (!inorderTraversal(root->left))
            return false;
        
        if (!visit(root))
            return false;
        
        return inorderTraversal(root->right);
    }
    bool visit(TreeNode* curNode)
    {
        if (!preNode)
        {

        }
        else if (!node1)
        {
            if (preNode->val > curNode->val)
            {
                node1 = preNode;
            }
        }
        else
        {
            if (node1->val < curNode->val)
            {
                node2 = preNode;
                return false;
            }
        }
        preNode = curNode;
        return true;
    }
    TreeNode* node1 = nullptr;
    TreeNode* node2 = nullptr;
    TreeNode* preNode = nullptr;
};

void Test()
{
    Solution solution;
    
    vector<int> values = {1, 2, 3, 4};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[2].get();
    nodes[2]->right = nodes[1].get();
    solution.recoverTree(nodes[0].get());
    
    int value = 1;
    for (auto& i : nodes)
    {
        i->val = value++;
        i->left = i->right = nullptr;
    }
    nodes[1]->left = nodes[0].get();
    nodes[1]->right = nodes[3].get();
    nodes[3]->left = nodes[2].get();
    solution.recoverTree(nodes[1].get());
}

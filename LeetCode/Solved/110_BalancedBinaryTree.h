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
    bool isBalanced(TreeNode* root)
    {
        return helper(root).first;
    }
private:
    pair<bool, int> helper(TreeNode* root)
    {
        if (root == nullptr)
            return make_pair(true, 0);
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        return make_pair(left.first && right.first && abs(left.second - right.second) <= 1, max(left.second, right.second) + 1);
    }
};

void Test()
{
    
}

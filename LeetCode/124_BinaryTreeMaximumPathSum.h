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
    int maxPathSum(TreeNode* root)
    {
        return helper(root).first;
    }
private:
    pair<int, int> helper(TreeNode* root)
    {
        if (root == nullptr)
            return {INT_MIN, 0};
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        int max1 = max(max(left.first, right.first), root->val + (left.second > 0 ? left.second : 0) + (right.second > 0 ? right.second : 0));
        int max2 = (max(left.second, right.second) > 0 ? max(left.second, right.second) : 0) + root->val;
        return {max1, max2};
    }
};

void Test()
{
    
}

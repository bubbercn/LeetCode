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
    int kthSmallest(TreeNode *root, int k)
    {
        lookup.clear();
        if (!root)
        {
            return 0;
        }
        int leftCount = getNodeCount(root->left);
        if (leftCount == k - 1)
        {
            return root->val;
        }
        else if (leftCount > k - 1)
        {
            return kthSmallest(root->left, k);
        }
        else
        {
            return kthSmallest(root->right, k - leftCount - 1);
        }
    }

private:
    unordered_map<TreeNode *, int> lookup;
    int getNodeCount(TreeNode *root)
    {
        if (!root)
            return 0;

        auto it = lookup.find(root);
        if (it != lookup.end())
        {
            return it->second;
        }

        int leftCount = root->left ? getNodeCount(root->left) : 0;
        int rightCount = root->right ? getNodeCount(root->right) : 0;
        int result = leftCount + rightCount + 1;
        lookup.emplace(root, result);
        return result;
    }
};

void Test()
{
}
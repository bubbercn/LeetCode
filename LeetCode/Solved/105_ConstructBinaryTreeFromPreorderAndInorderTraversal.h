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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        this->preorder = list<int>(preorder.begin(), preorder.end());
        return helper(inorder, 0, inorder.size());
    }
private:
    TreeNode* helper(vector<int>& inorder, size_t begin, size_t end)
    {
        if (preorder.empty())
            return nullptr;
        
        int rootValue = preorder.front();
        TreeNode* root = new TreeNode(rootValue);
        preorder.pop_front();

        size_t rootIndex = 0;
        for (size_t i = begin; i < end; i++)
        {
            if (inorder[i] == rootValue)
            {
                rootIndex = i;
                break;
            }
        }

        root->left = rootIndex > begin ? helper(inorder, begin, rootIndex) : nullptr;
        root->right = rootIndex + 1 < end ? helper(inorder, rootIndex + 1, end) : nullptr;
        
        return root;
    }
    list<int> preorder;
};

void Test()
{
    Solution solution;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    solution.buildTree(preorder, inorder);
}

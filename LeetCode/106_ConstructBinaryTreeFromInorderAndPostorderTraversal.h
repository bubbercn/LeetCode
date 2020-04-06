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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        this->postorder = list<int>(postorder.begin(), postorder.end());
        return helper(inorder, 0, inorder.size());
    }
private:
    TreeNode* helper(vector<int>& inorder, size_t begin, size_t end)
    {
        if (postorder.empty())
            return nullptr;
        
        int rootValue = postorder.back();
        TreeNode* root = new TreeNode(rootValue);
        postorder.pop_back();

        size_t rootIndex = 0;
        for (size_t i = begin; i < end; i++)
        {
            if (inorder[i] == rootValue)
            {
                rootIndex = i;
                break;
            }
        }

        root->right = rootIndex + 1 < end ? helper(inorder, rootIndex + 1, end) : nullptr;
        root->left = rootIndex > begin ? helper(inorder, begin, rootIndex) : nullptr;
        
        return root;
    }
    list<int> postorder;
};

void Test()
{
    Solution solution;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    solution.buildTree(inorder, postorder);
}

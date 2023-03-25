#pragma once
#include "Common.h"

class Solution
{
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        return helper(preorder.begin(), preorder.end(), postorder.begin(), postorder.end());
    }

private:
    TreeNode *helper(vector<int>::const_iterator preBegin, vector<int>::const_iterator preEnd, vector<int>::const_iterator postBegin, vector<int>::const_iterator postEnd)
    {
        if (preBegin == preEnd)
            return nullptr;
        
        TreeNode* root = new TreeNode(*preBegin);
        preBegin++;
        postEnd--; 

        if (preBegin == preEnd)
            return root;
        
        auto post = find(postBegin, postEnd, *preBegin);
        post++;
        auto pre = preBegin + distance(postBegin, post);
        root->left = helper(preBegin, pre, postBegin, post);

        if (pre == preEnd)
            return root;
        
        root->right = helper(pre, preEnd, post, postEnd);
        return root;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
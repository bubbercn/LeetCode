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
    bool isValidBST(TreeNode* root)
    {
        if (!root)
            return true;
        return get<0>(helper(root));
    }
private:
    tuple<bool, int, int> helper(TreeNode* root)
    {
        int min = root->val;
        int max = root->val;
        
        if (root->left)
        {
            auto temp = helper(root->left);
            if (!get<0>(temp))
                return make_tuple(false, min, max);
            if (get<2>(temp) >= root->val)
                return make_tuple(false, min, max);
            min = get<1>(temp);
        }
        
        if (root->right)
        {
            auto temp = helper(root->right);
            if (!get<0>(temp))
                return make_tuple(false, min, max);
            if (get<1>(temp) <= root->val)
                return make_tuple(false, min, max);
            max = get<2>(temp);
        }
        
        return make_tuple(true, min, max);
    }
};

void Test()
{
    
}

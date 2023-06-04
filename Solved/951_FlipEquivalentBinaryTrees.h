#pragma once
#include "Common.h"

class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 and !root2)
            return true;

        if (root1 and root2)
        {
            if (root1->val != root2->val)
                return false;

            return flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right) || flipEquiv(root1->left, root2->right) and flipEquiv(root1->right, root2->left);
        }
        else
        {
            return false;
        }
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

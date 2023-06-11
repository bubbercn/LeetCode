#pragma once
#include "Common.h"

class Solution
{
public:
    int minCameraCover(TreeNode *root)
    {
        return get<1>(helper(root));
    }

private:
    tuple<int, int, int> helper(TreeNode *root)
    {
        if (!root)
            return {numeric_limits<int>::max(), 0, 0};

        auto [la, lb, lc] = helper(root->left);
        auto [ra, rb, rc] = helper(root->right);
        int a = lc + rc + 1;
        int b = min(a, min(la + rb, lb + ra));
        int c = min(a, lb + rb);
        return {a, b, c};
    }
};

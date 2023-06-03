#pragma once
#include "Common.h"

class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        return helper(root).second != -1;
    }

private:
    pair<int, int> helper(TreeNode *root)
    {
        if (!root)
            return {0, 1};

        auto [lDepth, lComplete] = helper(root->left);
        if (lComplete == -1)
            return {-1, -1};

        auto [rDepth, rComplete] = helper(root->right);
        if (rComplete == -1)
            return {-1, -1};

        if (lComplete == 0 and rComplete == 0)
            return {-1, -1};

        if (lDepth == rDepth)
        {
            if (lComplete == rComplete)
            {
                return {lDepth + 1, 1};
            }
            else if (lComplete == 1)
            {
                return {lDepth + 1, 0};
            }
        }
        else if (lDepth == rDepth + 1 and rComplete == 1)
        {
            return {lDepth + 1, 0};
        }
        return {-1, -1};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
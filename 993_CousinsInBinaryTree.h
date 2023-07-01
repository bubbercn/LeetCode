#pragma once
#include "Common.h"

class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        auto [xDepth, xParent] = getDepth(root, x);
        auto [yDepth, yParent] = getDepth(root, y);
        return xDepth == yDepth && xParent != yParent;
    }

private:
    pair<int, TreeNode*> getDepth(TreeNode *root, int x)
    {
        if (root == nullptr)
            return {-1, nullptr};

        if (root->val == x)
            return {0, nullptr};

        auto [leftDepth, leftParent] = getDepth(root->left, x);
        if (leftDepth != -1)
        {
            if (leftParent == nullptr)
                return {leftDepth + 1, root};
            else
                return {leftDepth + 1, leftParent};
        }

        auto [rightDepth, rightParent] = getDepth(root->right, x);
        if (rightDepth != -1)
        {
            if (rightParent == nullptr)
                return {rightDepth + 1, root};
            else
                return {rightDepth + 1, rightParent};
        }
        
        return {-1, nullptr};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3));
    EXPECT_EQ(solution.isCousins(root, 4, 3), false);
    releaseTree(root);
}

TEST_F(LeetCodeTest, Example2)
{
    TreeNode *root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(4)), new TreeNode(3, nullptr, new TreeNode(5)));
    EXPECT_EQ(solution.isCousins(root, 5, 4), true);
    releaseTree(root);
}

TEST_F(LeetCodeTest, Example3)
{
    TreeNode *root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(4)), new TreeNode(3));
    EXPECT_EQ(solution.isCousins(root, 2, 3), false);
    releaseTree(root);
}
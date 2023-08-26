#pragma once
#include "Common.h"

class Solution
{
public:
    int distributeCoins(TreeNode *root)
    {
        return get<0>(dfs(root));
    }

private:
    tuple<int, int, int> dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {0, 0, 0};
        }
        auto [left, leftCount, leftSum] = dfs(root->left);
        auto [right, rightCount, rightSum] = dfs(root->right);
        int count = leftCount + rightCount + 1;
        int sum = leftSum + rightSum + root->val;
        int result = abs(leftSum - leftCount) + abs(rightSum - rightCount) + left + right;
        return {result, count, sum};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    EXPECT_EQ(solution.distributeCoins(root), 2);
    releaseTree(root);
}

TEST_F(LeetCodeTest, Example2)
{
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(3);
    root->right = new TreeNode(0);
    EXPECT_EQ(solution.distributeCoins(root), 3);
    releaseTree(root);
}
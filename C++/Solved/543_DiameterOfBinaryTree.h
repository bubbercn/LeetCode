#pragma once
#include "Common.h"

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        return helper(root).first;
    }

private:
    pair<int, int> helper(TreeNode *node)
    {
        if (node == nullptr)
            return {0, -1};
        
        auto [leftResult, leftDepth] = helper(node->left);
        auto [rightResult, rightDepth] = helper(node->right);
        int depth = max(leftDepth, rightDepth) + 1;
        int result = max(max(leftResult, rightResult), leftDepth + rightDepth + 2);
        return {result, depth};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> values = {1, 2, 3, 4, 5};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    nodes[1]->left = nodes[3].get();
    nodes[1]->right = nodes[4].get();
    EXPECT_EQ(solution.diameterOfBinaryTree(nodes[0].get()), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> values = {1, 2};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    EXPECT_EQ(solution.diameterOfBinaryTree(nodes[0].get()), 1);
}
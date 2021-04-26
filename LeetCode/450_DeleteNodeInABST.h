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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        return nullptr;
    }
};

class LeetCodeTest : public testing::Test
{
};

TEST_F(LeetCodeTest, Example1)
{
    // vector<int> values = {2, 1, 3};
    // vector<unique_ptr<TreeNode>> nodes;
    // for (auto i = values.begin(); i != values.end(); i++)
    // {
    //     nodes.emplace_back(new TreeNode(*i));
    // }
    // nodes[0]->left = nodes[1].get();
    // nodes[0]->right = nodes[2].get();
    // Codec c;
    // string tree = c.serialize(nodes[0].get());
    // TreeNode *root = c.deserialize(tree);
}
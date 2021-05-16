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
        target = nullptr;
        parent = nullptr;
        search(root, key);
        if (target == nullptr)
            return root;
        
        TreeNode* replacement = findReplacement();

        if (replacement != nullptr)
        {
            replacement->left = target->left;
            replacement->right = target->right;
        }

        if (parent != nullptr)
        {
            if (parent->left == target)
            {
                parent->left = replacement;
            }
            else
            {
                parent->right = replacement;
            }
            return root;
        }
        else
        {
            return replacement;
        }
    }

private:
    void search(TreeNode *root, int key)
    {
        if (root == nullptr)
            return;

        if (root->val == key)
        {
            target = root;
            return;
        }

        search(root->left, key);
        if (target != nullptr && parent == nullptr)
            parent = root;
        search(root->right, key);
        if (target != nullptr && parent == nullptr)
            parent = root;
    }

    TreeNode* findReplacement()
    {
        if (target == nullptr)
            return nullptr;
        
        if (target->left != nullptr)
        {
            TreeNode* result = target->left;
            TreeNode* parent = target;
            while (result->right != nullptr)
            {
                parent = result;
                result = result->right;
            }
            if (parent->left == result)
            {
                parent->left = result->left;
            }
            else
            {
                parent->right = result->left;
            }
            return result;
        }
        else if (target->right != nullptr)
        {
            TreeNode* result = target->right;
            TreeNode* parent = target;
            while (result->left != nullptr)
            {
                parent = result;
                result = result->left;
            }
            if (parent->left == result)
            {
                parent->left = result->right;
            }
            else
            {
                parent->right = result->right;
            }
            return result;
        }
        else
        {
            return nullptr;
        }
    }

    inline static TreeNode *target;
    inline static TreeNode *parent;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> values = {5, 3, 6, 2, 4, 7};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    nodes[1]->left = nodes[3].get();
    nodes[1]->right = nodes[4].get();
    nodes[2]->right = nodes[5].get();
    TreeNode *root = solution.deleteNode(nodes[0].get(), 3);
    EXPECT_EQ(root, nodes[0].get());
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> values = {5, 3, 6, 2, 4, 7};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    nodes[1]->left = nodes[3].get();
    nodes[1]->right = nodes[4].get();
    nodes[2]->right = nodes[5].get();
    TreeNode *root = solution.deleteNode(nodes[0].get(), 5);
    EXPECT_EQ(root, nodes[4].get());
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> values = {4,7,6,8,5,9};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->right = nodes[1].get();
    nodes[1]->left = nodes[2].get();
    nodes[1]->right = nodes[3].get();
    nodes[2]->left = nodes[4].get();
    nodes[3]->right = nodes[5].get();
    TreeNode *root = solution.deleteNode(nodes[0].get(), 7);
    EXPECT_EQ(root, nodes[0].get());
}
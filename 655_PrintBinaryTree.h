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
    vector<vector<string>> printTree(TreeNode *root)
    {
        int m = getHeight(root);
        int n = (1 << m) - 1;
        vector<vector<string>> result(m, vector<string>(n, ""));
        print(result, root, 0, (n - 1) / 2, m);
        return result;
    }

private:
    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    void print(vector<vector<string>> &result, TreeNode *root, int row, int column, int m)
    {
        if (root == nullptr)
            return;
        result[row][column] = to_string(root->val);
        int offset = pow(2, m - 2 - row);
        print(result, root->left, row + 1, column - offset, m);
        print(result, root->right, row + 1, column + offset, m);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

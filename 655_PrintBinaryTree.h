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
        if (!root)
            return {};

        auto leftResult = printTree(root->left);
        int lm = leftResult.size();
        int ln = leftResult.empty() ? 0 : leftResult[0].size();

        auto rightResult = printTree(root->right);
        int rm = rightResult.size();
        int rn = rightResult.empty() ? 0 : rightResult[0].size();

        int m = max(lm, rm) + 1;
        int n = max(ln, rn) * 2 + 1;
        vector<vector<string>> result(m, vector<string>(n, ""));

        result[0][n / 2] = to_string(root->val);
        int offset = (max(ln, rn) - ln) / 2;
        for (int i = 0; i < lm; i++)
        {
            for (int j = 0; j < ln; j++)
            {
                result[i + 1][j + offset] = leftResult[i][j];
            }
        }
        offset = n / 2 + 1 + (max(ln, rn) - rn) / 2;
        for (int i = 0; i < rm; i++)
        {
            for (int j = 0; j < rn; j++)
            {
                result[i + 1][j + offset] = rightResult[i][j];
            }
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

[
    [ "", "", "", "", "", "", "", "3", "", "", "", "", "", "", "" ],
    [ "", "", "", "1", "", "", "", "", "", "", "", "5", "", "", "" ],
    [ "", "0", "", "", "", "2", "", "", "", "", "4", "", "6", "", "" ],
    [ "", "", "", "", "", "", "3", "", "", "", "", "", "", "", "" ],
];

[
    [ "", "", "", "", "", "", "", "3", "", "", "", "", "", "", "" ],
    [ "", "", "", "1", "", "", "", "", "", "", "", "5", "", "", "" ],
    [ "", "0", "", "", "", "2", "", "", "", "4", "", "", "", "6", "" ],
    [ "", "", "", "", "", "", "3", "", "", "", "", "", "", "", "" ],
]
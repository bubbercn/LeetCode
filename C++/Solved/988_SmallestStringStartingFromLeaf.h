#pragma once
#include "Common.h"

class Solution
{
public:
    string smallestFromLeaf(TreeNode *root)
    {
        result.clear();
        dfs(root, "");
        return result;
    }

private:
    void dfs(TreeNode *root, string path)
    {
        path.push_back(alphabet[root->val]);
        if (root->left == nullptr && root->right == nullptr)
        {
            reverse(path.begin(), path.end());
            if (result.empty() || path < result)
            {
                result = path;
            }
            return;
        }
        if (root->left)
        {
            dfs(root->left, path);
        }
        if (root->right)
        {
            dfs(root->right, path);
        }
    }
    inline static string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string result;
};
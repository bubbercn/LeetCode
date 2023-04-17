#pragma once
#include "Common.h"

class CBTInserter
{
public:
    CBTInserter(TreeNode *root)
    {
        this->root = root;
        row.emplace(root);
        while (true)
        {
            while (!row.empty())
            {
                auto node = row.front();
                if (!node->left)
                {
                    return;
                }
                else
                {
                    nextRow.emplace(node->left);
                }
                if (!node->right)
                {
                    return;
                }
                else
                {
                    nextRow.emplace(node->right);
                }
                row.pop();
            }
            row.swap(nextRow);
        }
    }

    int insert(int val)
    {
        auto node = row.front();
        if (!node->left)
        {
            node->left = new TreeNode(val);
            nextRow.emplace(node->left);
            return node->val;
        }

        node->right = new TreeNode(val);
        nextRow.emplace(node->right);
        row.pop();
        if (row.empty())
            row.swap(nextRow);
        return node->val;
    }

    TreeNode *get_root()
    {
        return root;
    }

private:
    TreeNode *root;
    queue<TreeNode *> row;
    queue<TreeNode *> nextRow;
};


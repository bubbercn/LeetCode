#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        this->target = target;
        this->k = k;
        result.clear();

        dfs1(root);
        return result;
    }

private:
    bool dfs1(TreeNode *root)
    {
        if (!root)
            return false;

        if (root->val == target->val)
        {
            dfs2(root, k--);
            return true;
        }
        else
        {
            bool found = dfs1(root->left);
            if (found)
            {
                if (k == 0)
                {
                    result.emplace_back(root->val);
                    k--;
                }
                else if (k > 0)
                {
                    dfs2(root->right, --k);
                }
                return true;
            }
            else
            {
                found = dfs1(root->right);
                if (found)
                {
                    if (k == 0)
                    {
                        result.emplace_back(root->val);
                        k--;
                    }
                    else if (k > 0)
                    {
                        dfs2(root->left, --k);
                    }
                }
                return found;
            }
        }
    }
    void dfs2(TreeNode *root, int dis)
    {
        if (!root)
            return;

        if (dis == 0)
        {
            result.emplace_back(root->val);
            return;
        }

        dfs2(root->left, dis - 1);
        dfs2(root->right, dis - 1);
    }

private:
    TreeNode *target;
    int k;
    vector<int> result;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
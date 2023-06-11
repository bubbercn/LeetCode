#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        result.clear();
        this->voyage = &voyage;
        cur = 0;
        if (!dfs(root) || cur != this->voyage->size())
            return {-1};
        return result;
    }

private:
    bool dfs(TreeNode *root)
    {
        if (!root)
            return true;

        if (cur == voyage->size() || root->val != voyage->at(cur))
        {
            return false;
        }
        cur++;
        int temp = cur;
        if (auto lResult = dfs(root->left); !lResult)
        {
            cur = temp;
            swap(root->left, root->right);
            result.emplace_back(root->val);
            if (lResult = dfs(root->left); !lResult)
                return false;
        }
        return dfs(root->right);
    }
    vector<int> result;
    vector<int> *voyage;
    int cur;
};

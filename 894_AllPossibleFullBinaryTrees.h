#pragma once
#include "Common.h"

class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (auto it = cache.find(n); it != cache.end())
            return it->second;

        vector<TreeNode *> result;
        if (n == 1)
        {
            result.emplace_back(new TreeNode(0));
            cache.emplace(n, result);
            return result;
        }
        for (int left = 1; left < n; left++)
        {
            vector<TreeNode *> leftResult = allPossibleFBT(left);
            vector<TreeNode *> rightResult = allPossibleFBT(n - 1 - left);
            for (auto leftRoot : leftResult)
            {
                for (auto rightRoot : rightResult)
                {
                    auto root = new TreeNode(0);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    result.emplace_back(root);
                }
            }
        }
        cache.emplace(n, result);
        return result;
    }

private:
    unordered_map<int, vector<TreeNode *>> cache;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

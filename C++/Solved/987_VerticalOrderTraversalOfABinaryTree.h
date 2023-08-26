#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> lookup;
        dfs(root, 0, 0, lookup);
        vector<vector<int>> result;
        for (auto &col : lookup)
        {
            result.emplace_back();
            for (auto &row : col.second)
            {
                result.back().insert(result.back().end(), row.second.begin(), row.second.end());
            }
        }
        return result;
    }

private:
    void dfs(TreeNode *root, int row, int col, map<int, map<int, multiset<int>>> &lookup)
    {
        if (root == nullptr)
            return;
        lookup[col][row].emplace(root->val);
        dfs(root->left, row + 1, col - 1, lookup);
        dfs(root->right, row + 1, col + 1, lookup);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    TreeNode *root = new TreeNode{3, new TreeNode{9}, new TreeNode{20, new TreeNode{15}, new TreeNode{7}}};
    vector<vector<int>> output = {{9}, {3, 15}, {20}, {7}};
    EXPECT_EQ(solution.verticalTraversal(root), output);
    releaseTree(root);
}

TEST_F(LeetCodeTest, Example2)
{
    TreeNode *root = new TreeNode{1, new TreeNode{2, new TreeNode{4}, new TreeNode{5}}, new TreeNode{3, new TreeNode{6}, new TreeNode{7}}};
    vector<vector<int>> output = {{4}, {2}, {1, 5, 6}, {3}, {7}};
    EXPECT_EQ(solution.verticalTraversal(root), output);
    releaseTree(root);
}
#pragma once
#include "Common.h"

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        if (nums.empty())
            return nullptr;
        
        return helper(nums, 0, nums.size());
    }
private:
    TreeNode* helper(vector<int>& nums, size_t begin, size_t end)
    {
        size_t middle = (begin + end) / 2;
        TreeNode* root = new TreeNode(nums[middle]);
        
        root->left = middle > begin ? helper(nums, begin, middle) : nullptr;
        root->right = middle + 1 < end ? helper(nums, middle + 1, end) : nullptr;
        
        return root;
    }
};

void Test()
{
    Solution solution;
    
    vector<int> nums = {-10,-3,0,5,9};
    solution.sortedArrayToBST(nums);
}

class Solution1022 {
    public int sumRootToLeaf(TreeNode root) {
        return helper(root, 0);
    }

    private int helper(TreeNode root, int preSum) {
        if (root == null) {
            return 0;
        }
        preSum = preSum * 2 + root.val;
        if (root.left == null && root.right == null) {
            return preSum;
        }
        return helper(root.left, preSum) + helper(root.right, preSum);
    }

}
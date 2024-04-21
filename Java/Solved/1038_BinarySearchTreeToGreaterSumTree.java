class Solution1038 {
    public TreeNode bstToGst(TreeNode root) {
        helper(root, 0);
        return root;
    }

    private int helper(TreeNode root, int sum) {
        if (root == null)
            return 0;
        
        int right = helper(root.right, sum);
        int temp = root.val;
        root.val += right + sum;
        int left = helper(root.left, root.val);
        return left + right + temp;
    }
}
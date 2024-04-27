class Solution1080 {
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        if (dfs(root, limit - root.val) < limit) {
            return null;
        }
        return root;
    }

    private int dfs(TreeNode root, int limit) {
        if (root.left == null && root.right == null) {
            return root.val;
        }
        int left = Integer.MIN_VALUE;
        if (root.left != null) {
            left = dfs(root.left, limit - root.left.val);
            if (left < limit) {
                root.left = null;
            }
        }
        int right = Integer.MIN_VALUE;
        if (root.right != null) {
            right = dfs(root.right, limit - root.right.val);
            if (right < limit) {
                root.right = null;
            }
        }
        return root.val + Math.max(left, right);
    }
}
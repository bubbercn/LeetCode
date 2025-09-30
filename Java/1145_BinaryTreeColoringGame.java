class Solution1145 {
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        TreeNode nodeX = find(root, x);
        int leftCount = count(nodeX.left);
        int rightCount = count(nodeX.right);
        int other = n - leftCount - rightCount - 1;
        int max = Math.max(Math.max(leftCount, rightCount), other);
        if (max > n / 2) {
            return true;
        }
        return false;
    }

    private TreeNode find(TreeNode root, int x) {
        if (root == null) {
            return null;
        }
        if (root.val == x) {
            return root;
        }
        TreeNode left = find(root.left, x);
        if (left != null) {
            return left;
        }
        return find(root.right, x);
    }

    private int count(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + count(root.left) + count(root.right);
    }
}
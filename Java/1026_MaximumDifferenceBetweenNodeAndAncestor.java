class Solution1026 {
    public int maxAncestorDiff(TreeNode root) {
        if (root.left == null && root.right == null)
            return 0;

        int min = Integer.MAX_VALUE;
        if (root.left != null)
            min = Math.min(min, minValue(root.left));
        if (root.right != null)
            min = Math.min(min, minValue(root.right));

        int max = Integer.MIN_VALUE;
        if (root.left != null)
            max = Math.max(max, maxValue(root.left));
        if (root.right != null)
            max = Math.max(max, maxValue(root.right));

        int result = Math.max(Math.abs(root.val - min), Math.abs(root.val - max));
        if (root.left != null)
            result = Math.max(result, maxAncestorDiff(root.left));

        if (root.right != null)
            result = Math.max(result, maxAncestorDiff(root.right));

        return result;
    }

    private int minValue(TreeNode root) {
        int result = root.val;
        if (root.left != null) {
            result = Math.min(result, minValue(root.left));
        }
        if (root.right != null) {
            result = Math.min(result, minValue(root.right));
        }
        return result;
    }

    private int maxValue(TreeNode root) {
        int result = root.val;
        if (root.left != null) {
            result = Math.max(result, maxValue(root.left));
        }
        if (root.right != null) {
            result = Math.max(result, maxValue(root.right));
        }
        return result;
    }
}
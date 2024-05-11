class Solution1123 {
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return dfs(root).node;
    }

    private Result dfs(TreeNode node) {
        if (node == null) {
            return new Result(null, 0);
        }

        Result left = dfs(node.left);
        Result right = dfs(node.right);
        int depth = Math.max(left.depth, right.depth) + 1;
        if (depth == 1) {
            return new Result(node, 1);
        }
        if (left.depth == right.depth) {
            return new Result(node, depth);
        }
        return new Result(left.depth > right.depth ? left.node : right.node, depth);
    }

    class Result {
        TreeNode node;
        int depth;

        Result(TreeNode node, int depth) {
            this.node = node;
            this.depth = depth;
        }
    }
}
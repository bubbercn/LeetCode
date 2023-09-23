class Solution1008 {
    public TreeNode bstFromPreorder(int[] preorder) {
        return helper(preorder, 0, preorder.length);
    }

    private TreeNode helper(int[] preorder, int start, int end) {
        if (preorder == null || start == end)
            return null;
        int rootVal = preorder[start];
        TreeNode root = new TreeNode(rootVal);
        int leftEnd = 0;
        for (int i = start + 1; i < end; i++) {
            if (preorder[i] > rootVal) {
                leftEnd = i;
                break;
            }
        }
        if (leftEnd == 0)
            leftEnd = end;
        root.left = helper(preorder, start + 1, leftEnd);
        root.right = helper(preorder, leftEnd, end);
        return root;
    }
}
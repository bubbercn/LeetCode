class Solution1028 {
    public TreeNode recoverFromPreorder(String traversal) {
        return helper(traversal, 0, traversal.length());
    }

    private TreeNode helper(String traversal, int begin, int end) {
        int depth = 0;
        int i = begin;
        while (i < end) {
            if (traversal.charAt(i) == '-') {
                depth++;
                i++;
            } else {
                break;
            }
        }
        int val = 0;
        while (i < end) {
            if (traversal.charAt(i) == '-') {
                break;
            } else {
                val = val * 10 + (traversal.charAt(i) - '0');
                i++;
            }
        }
        TreeNode root = new TreeNode(val);
        if (i == end) {
            return root;
        }

        depth++;
        int j = end - 1;
        int count = 0;
        while (j >= i) {
            if (traversal.charAt(j) == '-') {
                count++;
            } else {
                if (count == depth)
                    break;
                count = 0;
            }
            j--;
        }
        j++;
        if (j == i) {
            root.left = helper(traversal, i, end);
            return root;
        } else {
            root.left = helper(traversal, i, j);
            root.right = helper(traversal, j, end);
            return root;
        }
    }
}
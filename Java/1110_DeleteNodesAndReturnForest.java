import java.util.List;
import java.util.Set;
import java.util.HashSet;
import java.util.LinkedList;

class Solution1110 {
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        Set<Integer> toDelete = new HashSet<>();
        for (int i : to_delete) {
            toDelete.add(i);
        }
        List<TreeNode> result = new LinkedList<>();
        helper(root, toDelete, result, true);
        return result;
    }

    private boolean helper(TreeNode root, Set<Integer> toDelete, List<TreeNode> result, boolean isRoot) {
        if (root == null) {
            return false;
        }
        boolean deleted = toDelete.contains(root.val);
        if (isRoot && !deleted) {
            result.add(root);
        }
        if (helper(root.left, toDelete, result, deleted)) {
            root.left = null;
        }
        if (helper(root.right, toDelete, result, deleted)) {
            root.right = null;
        }
        return deleted;
    }
}
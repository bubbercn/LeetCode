import java.util.ArrayList;
import java.util.List;

class Solution1161 {
    public int maxLevelSum(TreeNode root) {
        List<TreeNode> queue = new ArrayList<>();
        queue.add(root);
        int result = 0;
        int level = 0;
        int maxSum = Integer.MIN_VALUE;
        while (!queue.isEmpty()) {
            List<TreeNode> next = new ArrayList<>();
            int sum = 0;
            for (TreeNode node : queue) {
                sum += node.val;
                if (node.left != null) {
                    next.add(node.left);
                }
                if (node.right != null) {
                    next.add(node.right);
                }
            }
            queue = next;
            level++;
            if (sum > maxSum) {
                maxSum = sum;
                result = level;
            }
        }
        return result;
    }
}
import org.junit.Test;

public class Test1080 {
    Solution1080 solution = new Solution1080();

    @Test
    public void Example3() {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(-5);
        root.right = new TreeNode(-3);
        root.right.left = new TreeNode(4);
        TreeNode result = solution.sufficientSubset(root, -1);
    }
}

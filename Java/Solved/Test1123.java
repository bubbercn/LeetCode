import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1123 {
    Solution1123 solution = new Solution1123();

    @Test
    public void Example1() {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(5);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(6);
        root.left.right = new TreeNode(2);
        root.left.right.left = new TreeNode(7);
        root.left.right.right = new TreeNode(4);
        root.right.left = new TreeNode(0);
        root.right.right = new TreeNode(8);
        assertEquals(2, solution.lcaDeepestLeaves(root).val);
    }
}

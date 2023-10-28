import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1026 {
    Solution1026 solution = new Solution1026();

    @Test
    public void Case1() {
        TreeNode root = new TreeNode(8);
        root.left = new TreeNode(3);
        root.right = new TreeNode(10);
        assertEquals(5, solution.maxAncestorDiff(root));
    }
}

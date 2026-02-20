import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1145 {
    Solution1145 solution = new Solution1145();

    @Test
    public void Example1() {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        int n = 3;
        int x = 1;
        assertEquals(false, solution.btreeGameWinningMove(root, n, x));
    }

}

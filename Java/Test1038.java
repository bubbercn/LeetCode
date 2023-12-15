import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1038 {
    Solution1038 solution = new Solution1038();

    @Test
    public void Example1() {
        TreeNode root = new TreeNode(0);
        root.right = new TreeNode(1);
        TreeNode expect = new TreeNode(1);
        expect.right = new TreeNode(1);
        assertEquals(expect, solution.bstToGst(root));
    }
}

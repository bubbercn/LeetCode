import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1022 {
    Solution1022 solution = new Solution1022();

    @Test
    public void Example1() {
        TreeNode root = new TreeNode(0);
        assertEquals(0, solution.sumRootToLeaf(root));
    }
}

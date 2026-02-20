import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1161 {
    Solution1161 solution = new Solution1161();
    
     @Test
     public void Example1() {
         TreeNode root = new TreeNode(1);
         root.left = new TreeNode(7);
         root.right = new TreeNode(0);
         root.left.left = new TreeNode(7);
         root.left.right = new TreeNode(-8);
         assertEquals(7, solution.maxLevelSum(root));
     }

     @Test
     public void Example2() {
         TreeNode root = new TreeNode(989);
         root.right = new TreeNode(10250);
         root.right.left = new TreeNode(98693);
         root.right.right = new TreeNode(-89388);
         root.right.right.left = new TreeNode(-32127);
         assertEquals(10250, solution.maxLevelSum(root));
     }
}

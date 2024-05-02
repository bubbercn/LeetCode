import org.junit.Test;

public class Test1110 {
    Solution1110 solution = new Solution1110();

    @Test
    public void Example1() {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);
        int[] to_delete = new int[] { 3, 5 };
        solution.delNodes(root, to_delete);
    }
}

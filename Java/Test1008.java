import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1008 {
    Solution1008 solution = new Solution1008();

    @Test
    public void Example1() {
        int[] preorder = { 8, 5, 1, 7, 10, 12 };
        solution.bstFromPreorder(preorder);
    }

    @Test
    public void Example2() {
        int[] preorder = { 1, 3 };
        solution.bstFromPreorder(preorder);
    }
}

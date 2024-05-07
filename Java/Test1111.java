import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1111 {
    Solution1111 solution = new Solution1111();

    @Test
    public void Example1() {
        int[] expected = new int[] { 0, 1, 1, 1, 1, 0 };
        assertArrayEquals(expected, solution.maxDepthAfterSplit("(()())"));
    }

    @Test
    public void Example2() {
        int[] expected = new int[] { 0, 0, 0, 1, 1, 0, 0, 0 };
        assertArrayEquals(expected, solution.maxDepthAfterSplit("()(())()"));
    }
}

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1111 {
    Solution1111 solution = new Solution1111();

    @Test
    public void Example1() {
        int[] expected = new int[] { 0, 1, 1, 1, 0 };
        assertEquals(expected, solution.maxDepthAfterSplit("(()())"));
    }

    @Test
    public void Example2() {
        int[] expected = new int[] { 0, 0, 0, 1, 1, 0, 0, 0 };
        assertEquals(expected, solution.maxDepthAfterSplit("()(())()"));
    }
}

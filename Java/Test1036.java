import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1036 {
    Solution1036 solution = new Solution1036();

    @Test
    public void Example1() {
        int[][] blocked = { { 0, 1 }, { 1, 0 } };
        int[] source = { 0, 0 };
        int[] target = { 0, 2 };
        assertEquals(false, solution.isEscapePossible(blocked, source, target));
    }

    @Test
    public void Example2() {
        int[][] blocked = {};
        int[] source = { 0, 0 };
        int[] target = { 999999, 999999 };
        assertEquals(true, solution.isEscapePossible(blocked, source, target));
    }
}

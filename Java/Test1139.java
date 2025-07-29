import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1139 {
    Solution1139 solution = new Solution1139();

    @Test
    public void Example1() {
        int[][] grid = { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };
        assertEquals(9, solution.largest1BorderedSquare(grid));
    }

    @Test
    public void Example2() {
        int[][] grid = { { 1, 1, 0, 0 } };
        assertEquals(1, solution.largest1BorderedSquare(grid));
    }
}

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1091 {
    Solution1091 solution = new Solution1091();

    @Test
    public void Example1() {
        int[][] grid = { { 0, 1 }, { 1, 0 } };
        assertEquals(2, solution.shortestPathBinaryMatrix(grid));
    }

    @Test
    public void Example2() {
        int[][] grid = { { 0, 0, 0 }, { 1, 1, 0 }, { 1, 1, 0 } };
        assertEquals(4, solution.shortestPathBinaryMatrix(grid));
    }

    @Test
    public void Example3() {
        int[][] grid = { { 1, 0, 0 }, { 1, 1, 0 }, { 1, 1, 0 } };
        assertEquals(-1, solution.shortestPathBinaryMatrix(grid));
    }
}

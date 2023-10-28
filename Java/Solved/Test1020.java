import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1020 {
    Solution1020 solution = new Solution1020();

    @Test
    public void Example1() {
        int[][] grid = new int[][] { { 0, 0, 0, 0 }, { 1, 0, 1, 0 }, { 0, 1, 1, 0 }, { 0, 0, 0, 0 } };
        assertEquals(3, solution.numEnclaves(grid));
    }

    @Test
    public void Example2() {
        int[][] grid = new int[][] { { 0, 1, 1, 0 }, { 0, 0, 1, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 0 } };
        assertEquals(0, solution.numEnclaves(grid));
    }
}

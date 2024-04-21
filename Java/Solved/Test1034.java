import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1034 {
    Solution1034 solution = new Solution1034();

    @Test
    public void Example1() {
        int[][] grid = { { 1, 1 }, { 1, 2 } };
        int[][] expected = { { 3, 3}, { 3, 2 } };
        assertArrayEquals(expected, solution.colorBorder(grid, 0, 0, 3));
    }

    @Test
    public void Example2() {
        int[][] grid = { { 1, 2, 2 }, { 2, 3, 2 } };
        int[][] expected = { { 1, 3, 3 }, { 2, 3, 3 } };
        assertArrayEquals(expected, solution.colorBorder(grid, 0, 1, 3));
    }

    @Test
    public void Example3() {
        int[][] grid = { { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } };
        int[][] expected = { { 2, 2, 2 }, { 2, 1, 2 }, { 2, 2, 2 } };
        assertArrayEquals(expected, solution.colorBorder(grid, 1, 1, 2));
    }
}

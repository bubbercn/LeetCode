import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1162 {
    Solution1162 solution = new Solution1162();

    @Test
    public void Example1() {
        int[][] grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
        assertEquals(2, solution.maxDistance(grid));
    }

    @Test
    public void Example2() {
        int[][] grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        assertEquals(4, solution.maxDistance(grid));
    }
}

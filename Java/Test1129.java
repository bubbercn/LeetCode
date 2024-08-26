import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1129 {
    Solution1129 solution = new Solution1129();

    @Test
    public void Example1() {
        int[][] redEdges = new int[][] { { 0, 1 }, { 1, 2 } };
        int[][] blueEdges = new int[][] {};
        int[] expected = new int[] { 0, 1, -1 };
        assertArrayEquals(expected, solution.shortestAlternatingPaths(3, redEdges, blueEdges));
    }

    @Test
    public void Example2() {
        int[][] redEdges = new int[][] { { 0, 1 } };
        int[][] blueEdges = new int[][] { { 2, 1 } };
        int[] expected = new int[] { 0, 1, -1 };
        assertArrayEquals(expected, solution.shortestAlternatingPaths(3, redEdges, blueEdges));
    }
}

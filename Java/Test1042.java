import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1042 {
    Solution1042 solution = new Solution1042();

    @Test
    public void Example1() {
        int n = 3;
        int[][] paths = new int[][] { { 1, 2 }, { 2, 3 }, { 3, 1 } };
        int[] expected = new int[] { 1, 2, 3 };
        assertArrayEquals(expected, solution.gardenNoAdj(n, paths));
    }

    @Test
    public void Example2() {
        int n = 4;
        int[][] paths = new int[][] { { 1, 2 }, { 3, 4 } };
        int[] expected = new int[] { 1, 2, 1, 2 };
        assertArrayEquals(expected, solution.gardenNoAdj(n, paths));
    }

    @Test
    public void Example3() {
        int n = 4;
        int[][] paths = new int[][] { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 1 }, { 1, 3 }, { 2, 4 } };
        int[] expected = new int[] { 1, 2, 3, 4 };
        assertArrayEquals(expected, solution.gardenNoAdj(n, paths));
    }
}

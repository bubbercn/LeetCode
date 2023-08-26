import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Solution1001Test {

    Solution1001 solution = new Solution1001();

    @Test
    public void Example1() {
        int[][] lamps = { { 0, 0 }, { 4, 4 } };
        int[][] queries = { { 1, 1 }, { 1, 0 } };
        int[] output = { 1, 0 };
        assertArrayEquals(solution.gridIllumination(5, lamps, queries), output);
    }

    @Test
    public void Example2() {
        int[][] lamps = { { 0, 0 }, { 4, 4 } };
        int[][] queries = { { 1, 1 }, { 1, 1 } };
        int[] output = { 1, 1 };
        assertArrayEquals(solution.gridIllumination(5, lamps, queries), output);
    }

    @Test
    public void Example3() {
        int[][] lamps = { { 0, 0 }, { 0, 4 } };
        int[][] queries = { { 0, 4 }, { 0, 1 }, { 1, 4 } };
        int[] output = { 1, 1, 0 };
        assertArrayEquals(solution.gridIllumination(5, lamps, queries), output);
    }
}
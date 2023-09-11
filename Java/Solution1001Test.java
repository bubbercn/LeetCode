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

    @Test
    public void Failure1() {
        int[][] lamps = { { 2, 5 }, { 4, 2 }, { 0, 3 }, { 0, 5 }, { 1, 4 }, { 4, 2 }, { 3, 3 }, { 1, 0 } };
        int[][] queries = { { 4, 3 }, { 3, 1 }, { 5, 3 }, { 0, 5 }, { 4, 4 }, { 3, 3 } };
        int[] output = { 1, 0, 1, 1, 0, 1 };
        assertArrayEquals(solution.gridIllumination(6, lamps, queries), output);
    }
}
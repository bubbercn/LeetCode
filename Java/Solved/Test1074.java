import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1074 {
    Solution1074 solution1074 = new Solution1074();

    @Test
    public void Example1() {
        int[][] matrix = { { 0, 1, 0 }, { 1, 1, 1 }, { 0, 1, 0 } };
        assertEquals(4, solution1074.numSubmatrixSumTarget(matrix, 0));
    }

    @Test
    public void Example2() {
        int[][] matrix = { { 1, -1 }, { -1, 1 } };
        assertEquals(5, solution1074.numSubmatrixSumTarget(matrix, 0));
    }

    @Test
    public void Example3() {
        int[][] matrix = { { 904 } };
        assertEquals(0, solution1074.numSubmatrixSumTarget(matrix, 0));
    }
}

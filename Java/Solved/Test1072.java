import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Test1072 {
    Solution1072 solution1072 = new Solution1072();

    @Test
    public void Example1() {
        int[][] matrix = { { 0, 1 }, { 1, 1 } };
        assertEquals(1, solution1072.maxEqualRowsAfterFlips(matrix));
    }

    @Test
    public void Example2() {
        int[][] matrix = { { 0, 1 }, { 1, 0 } };
        assertEquals(2, solution1072.maxEqualRowsAfterFlips(matrix));
    }

    @Test
    public void Example3() {
        int[][] matrix = { { 0, 0, 0 }, { 0, 0, 1 }, { 1, 1, 0 } };
        assertEquals(2, solution1072.maxEqualRowsAfterFlips(matrix));
    }
}

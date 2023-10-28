import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1030 {
    Solution1030 solution1030 = new Solution1030();

    @Test
    public void Example1() {
        int[][] expected = { { 0, 0 }, { 0, 1 } };
        assertArrayEquals(expected, solution1030.allCellsDistOrder(1, 2, 0, 0));
    }

    @Test
    public void Example2() {
        int[][] expected = { { 0, 1 }, { 0, 0 }, { 1, 1 }, { 1, 0 } };
        assertArrayEquals(expected, solution1030.allCellsDistOrder(2, 2, 0, 1));
    }

    @Test
    public void Example3() {
        int[][] expected = { { 1, 2 }, { 0, 2 }, { 1, 1 }, { 0, 1 }, { 1, 0 }, { 0, 0 } };
        assertArrayEquals(expected, solution1030.allCellsDistOrder(2, 3, 1, 2));
    }
}

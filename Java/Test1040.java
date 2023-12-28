import static org.junit.Assert.assertArrayEquals;

import org.junit.Test;

public class Test1040 {
    Solution1040 solution = new Solution1040();

    @Test
    public void Example1() {
        int[] stones = new int[] { 7, 4, 9 };
        int[] expected = new int[] { 1, 2 };
        assertArrayEquals(expected, solution.numMovesStonesII(stones));
    }

    @Test
    public void Example2() {
        int[] stones = new int[] { 6, 5, 4, 3, 10 };
        int[] expected = new int[] { 2, 3 };
        assertArrayEquals(expected, solution.numMovesStonesII(stones));
    }
}

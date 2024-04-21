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

    @Test
    public void Failure1() {
        int[] stones = new int[] { 8, 7, 6, 5, 2 };
        int[] expected = new int[] { 2, 2 };
        assertArrayEquals(expected, solution.numMovesStonesII(stones));
    }

    @Test
    public void Failure2() {
        int[] stones = new int[] { 1, 500000000, 1000000000 };
        int[] expected = new int[] { 2, 499999999 };
        assertArrayEquals(expected, solution.numMovesStonesII(stones));
    }
}
